# Copyright (C) 2010 Peter Johnson
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  - Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  - Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND OTHER CONTRIBUTORS ``AS IS''
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR OTHER CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

"""Robot Communication Management."""

try:
    from . import frccomm
except ValueError:
    import frccomm
import socket
import time
import threading

__all__ = ["RobotComm"]

class RobotCommThread(threading.Thread):
    def __init__(self, team_id, robot_addr, ds_addr):
        super().__init__()
        self.daemon = True

        self.team_id = team_id
        self.robot_addr = robot_addr
        self.ds_addr = ds_addr
        self.state = frccomm.RobotState()

        self.mutex = threading.Lock()
        self.new_data_cv = threading.Condition(self.mutex)
        self.resync_cv = threading.Condition(self.mutex)
        self.reset_event = threading.Event()
        self.stop_event = threading.Event()

        self.code_running = False

    def run(self):
        ds_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        robot_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        robot_sock.bind(self.robot_addr)
        ds_packet = bytearray(frccomm.CONTROL_PACKET_SIZE)

        while not self.stop_event.is_set():
            nbytes, address = robot_sock.recvfrom_into(ds_packet)
            if nbytes != frccomm.CONTROL_PACKET_SIZE:
                continue

            self.mutex.acquire()
            try:
                self.state.unpacketize_command(ds_packet)
                self.new_data_cv.notify_all()

                # Handle reset and resync
                if (not self.reset_event.is_set() and
                        self.state.control.control.reset):
                    self.reset_event.set()
                    print("Resetting...")
                    self.mutex.release()
                    time.sleep(10)
                    self.mutex.acquire()
                    print("Done with reset.")

                if (self.reset_event.is_set() and
                        not self.state.control.control.reset):
                    self.reset_event.clear()
                    print("Out of reset")

                #if self.do_reset and self.state.control.resync:
                #    self.state.control.reset = False
                #    self.state.control.resync = False
                #    print("Resync")

                if not self.code_running:
                    self.state.status.stop_user()
                else:
                    self.state.status.battery = 10.8
                packet = self.state.packetize_status()
            finally:
                self.mutex.release()
            ds_sock.sendto(packet, self.ds_addr)

class RobotComm:
    def __init__(self, team_id,
                 robot_addr=None, robot_port=frccomm.ROBOT_PORT,
                 ds_addr=None, ds_port=frccomm.DS_PORT):
        # Default robot and DS IP addresses if unspecified
        team_hi, team_lo = divmod(team_id, 100)
        if robot_addr is None:
            robot_addr = "10.%d.%d.2" % (team_hi, team_lo)
        robot_addr = (robot_addr, robot_port)
        if ds_addr is None:
            ds_addr = "10.%d.%d.5" % (team_hi, team_lo)
        ds_addr = (ds_addr, ds_port)

        self._thread = RobotCommThread(team_id, robot_addr, ds_addr)
        self._thread.start()

    # void getFPGAHardwareVersion(UINT16 *fpgaVersion, UINT32 *fpgaRevision);
    # int get_common_control_data(FRCCommonControlData *data, int wait_ms);
    # int get_dynamic_control_data(UINT8 type, char *dynamicData, INT32 maxLength, int wait_ms);

    def stop(self):
        self._thread.stop_event.set()
        self._thread.join()

    def set_status_data(self, battery, ds_digital_out, update_number,
                        user_data_high, user_data_low, wait_ms):
        with self._thread.mutex:
            self._thread.status.battery = battery
            self._thread.status.ds_digital_out[None] = ds_digital_out
            self._thread.status.user_update_number = update_number
            self._thread.status.user_data_high = user_data_high
            self._thread.status.user_data_low = user_data_low

    def set_error_data(self, errors, wait_ms):
        with self._thread.mutex:
            self._thread.status.errors = errors

    def set_user_ds_lcd_data(self, user_ds_lcd_data, wait_ms):
        with self._thread.mutex:
            self._thread.status.ds_lcd_data = user_ds_lcd_data

    def override_io_config(self, io_config, wait_ms):
        pass

    def get_new_data_cv(self):
        return self._thread.new_data_cv

    def get_resync_cv(self, sem):
        return self._thread.resync_cv

    def signal_resync_action_done(self):
        pass

    def observe_user_program_starting(self):
        with self._thread.mutex:
            self._thread.code_running = True

    def observe_user_program_stopping(self):
        with self._thread.mutex:
            self._thread.code_running = False

    # void FRC_NetworkCommunication_getVersionString(char *version);


if __name__ == "__main__":
    rc = RobotComm(294, robot_addr="127.0.0.1", ds_addr="127.0.0.1")

    import msvcrt
    while 1:
        if msvcrt.kbhit():
            ch = ord(msvcrt.getch())
            if ch == ord('Q'):
                break
            elif ch == ord('S'):
                print("Starting user code.")
                rc.observe_user_program_starting()
            elif ch == ord('s'):
                print("Stopping user code.")
                rc.observe_user_program_stopping()
        time.sleep(0.02)

