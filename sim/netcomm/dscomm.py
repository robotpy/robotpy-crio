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

"""Driver Station Communication Management."""

from . import frccomm
import socket
import time
import threading

__all__ = ["DriverStationComm"]

class DSTransmitThread(threading.Thread):
    def __init__(self, parent):
        super().__init__()
        self.daemon = True
        self.parent = parent

    def run(self):
        robot_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        while not self.parent.stop_event.is_set():
            with self.parent.mutex:
                self.parent.state.control.packet_index += 1
                packet = self.parent.state.packetize_command()
            robot_sock.sendto(packet, self.parent.robot_addr)
            time.sleep(0.02)

class DSReceiveThread(threading.Thread):
    def __init__(self, parent):
        super().__init__()
        self.daemon = True
        self.parent = parent

    def run(self):
        ds_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        ds_sock.bind(self.parent.ds_addr)
        ds_sock.settimeout(0.2)
        robot_packet = bytearray(frccomm.STATUS_MAX_PACKET_SIZE)

        while not self.parent.stop_event.is_set():
            try:
                nbytes, address = ds_sock.recvfrom_into(robot_packet)
            except socket.timeout:
                continue
            if nbytes < frccomm.STATUS_BASE_PACKET_SIZE:
                continue

            with self.parent.mutex:
                self.parent.state.unpacketize_status(robot_packet)
                self.parent.have_data.set()
                self.parent.new_data_cv.notify_all()

class DriverStationComm:
    def __init__(self, team_id,
                 robot_addr=None, robot_port=frccomm.ROBOT_PORT,
                 ds_addr=None, ds_port=frccomm.DS_PORT):
        # Default robot and DS IP addresses if unspecified
        team_hi, team_lo = divmod(team_id, 100)
        if robot_addr is None:
            robot_addr = "10.%d.%d.2" % (team_hi, team_lo)
        self.robot_addr = (robot_addr, robot_port)
        if ds_addr is None:
            ds_addr = "10.%d.%d.5" % (team_hi, team_lo)
        self.ds_addr = (ds_addr, ds_port)

        self.team_id = team_id
        self.state = frccomm.DriverStationState()
        self.mutex = threading.Lock()
        self.new_data_cv = threading.Condition(self.mutex)
        self.have_data = threading.Event()

        self.stop_event = threading.Event()

        self._recv_thread = DSReceiveThread(self)
        self._recv_thread.start()
        self._xmit_thread = DSTransmitThread(self)
        self._xmit_thread.start()

    def stop(self):
        self.stop_event.set()
        self._xmit_thread.join()
        self._recv_thread.join()

