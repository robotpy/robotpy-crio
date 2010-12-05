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

"""
frccomm.py - FRC network communication protocol
"""

import struct
from zlib import crc32
try:
    from .bf import bf
except ValueError:
    from bf import bf

__all__ = [ "ROBOT_PORT", "DS_PORT", "DASHBOARD_PORT", "CONSOLE_PORT",
            "CONTROL_PACKET_SIZE", "STATUS_BASE_PACKET_SIZE",
            "IO_CONFIG_DATA_SIZE", "USER_STATUS_DATA_SIZE",
            "USER_DS_LCD_DATA_SIZE", "STATUS_MAX_PACKET_SIZE",
            "FRCControlByte", "JoystickState", "FRCCommonControlData",
            "RobotStatusData", "EnhancedIOControl", "EnhancedIOStatus",
            "DriverStationState", "RobotState", "DashboardState" ]

ROBOT_PORT = 1110
DS_PORT = 1150
DASHBOARD_PORT = 1165
CONSOLE_PORT = 6666

CONTROL_PACKET_SIZE = 0x400
STATUS_BASE_PACKET_SIZE = 0x400
IO_CONFIG_DATA_SIZE = 32
USER_STATUS_DATA_SIZE = 984 - IO_CONFIG_DATA_SIZE
USER_DS_LCD_DATA_SIZE = 128
STATUS_MAX_PACKET_SIZE = STATUS_BASE_PACKET_SIZE + USER_DS_LCD_DATA_SIZE

def indexed_property(name, index):
    def getter(self):
        return getattr(self, name)[index]
    def setter(self, value):
        getattr(self, name)[index] = value
    return property(getter, setter)

class FRCControlByte:
    def __init__(self):
        self.value = bf(0x40)

    def __int__(self):
        return int(self.value)

    def set(self, value):
        self.value[None] = value

    reset = indexed_property('value', 7)
    enabled = indexed_property('value', 5)
    autonomous = indexed_property('value', 4)
    fms_attached = indexed_property('value', 3)
    resync = indexed_property('value', 2)
    crio_chksum = indexed_property('value', 1)
    fpga_chksum = indexed_property('value', 0)

    # estop is inverted in the packet
    @property
    def estop(self):
        return not self.value[6]
    @estop.setter
    def estop(self, value):
        self.value[6] = not value

class JoystickState:
    def __init__(self):
        self.axes = [0] * 6
        self.buttons = bf()

class FRCCommonControlData:
    _struct_def = struct.Struct('>HBBH cc 6bH 6bH 6bH 6bH 4H Q4L 8s')

    def __init__(self):
        self.packet_index = 0
        self.control = FRCControlByte()
        self.ds_digital_in = bf(0xff)
        self.team_id = 0
        self.alliance = 'R'
        self.position = '1'
        self.sticks = [JoystickState() for i in range(4)]
        self.analogs = [0] * 4
        self.crio_checksum = 0
        self.fpga_checksum = [0] * 4
        self.ds_version = '10020800'

    def pack_into(self, array, offset=0):
        self._struct_def.pack_into(array, offset,
                self.packet_index,
                int(self.control),
                int(self.ds_digital_in),
                self.team_id,
                self.alliance,
                self.position,
                self.sticks[0].axes[0],
                self.sticks[0].axes[1],
                self.sticks[0].axes[2],
                self.sticks[0].axes[3],
                self.sticks[0].axes[4],
                self.sticks[0].axes[5],
                int(self.sticks[0].buttons),
                self.sticks[1].axes[0],
                self.sticks[1].axes[1],
                self.sticks[1].axes[2],
                self.sticks[1].axes[3],
                self.sticks[1].axes[4],
                self.sticks[1].axes[5],
                int(self.sticks[1].buttons),
                self.sticks[2].axes[0],
                self.sticks[2].axes[1],
                self.sticks[2].axes[2],
                self.sticks[2].axes[3],
                self.sticks[2].axes[4],
                self.sticks[2].axes[5],
                int(self.sticks[2].buttons),
                self.sticks[3].axes[0],
                self.sticks[3].axes[1],
                self.sticks[3].axes[2],
                self.sticks[3].axes[3],
                self.sticks[3].axes[4],
                self.sticks[3].axes[5],
                int(self.sticks[3].buttons),
                self.analogs[0],
                self.analogs[1],
                self.analogs[2],
                self.analogs[3],
                self.crio_checksum,
                self.fpga_checksum[0],
                self.fpga_checksum[1],
                self.fpga_checksum[2],
                self.fpga_checksum[3],
                self.ds_version)

    def unpack_from(self, array, offset=0):
        (self.packet_index,
         self.control.value[None],
         self.ds_digital_in[None],
         self.team_id,
         self.alliance,
         self.position,
         self.sticks[0].axes[0],
         self.sticks[0].axes[1],
         self.sticks[0].axes[2],
         self.sticks[0].axes[3],
         self.sticks[0].axes[4],
         self.sticks[0].axes[5],
         self.sticks[0].buttons[None],
         self.sticks[1].axes[0],
         self.sticks[1].axes[1],
         self.sticks[1].axes[2],
         self.sticks[1].axes[3],
         self.sticks[1].axes[4],
         self.sticks[1].axes[5],
         self.sticks[1].buttons[None],
         self.sticks[2].axes[0],
         self.sticks[2].axes[1],
         self.sticks[2].axes[2],
         self.sticks[2].axes[3],
         self.sticks[2].axes[4],
         self.sticks[2].axes[5],
         self.sticks[2].buttons[None],
         self.sticks[3].axes[0],
         self.sticks[3].axes[1],
         self.sticks[3].axes[2],
         self.sticks[3].axes[3],
         self.sticks[3].axes[4],
         self.sticks[3].axes[5],
         self.sticks[3].buttons[None],
         self.analogs[0],
         self.analogs[1],
         self.analogs[2],
         self.analogs[3],
         self.crio_checksum,
         self.fpga_checksum[0],
         self.fpga_checksum[1],
         self.fpga_checksum[2],
         self.fpga_checksum[3],
         self.ds_version) = \
                 self._struct_def.unpack_from(array, offset)

class RobotStatusData:
    def __init__(self):
        self.control = FRCControlByte()
        self.battery_int = 0x37
        self.battery_frac = 0x37
        self.ds_digital_out = bf()
        self.mac_addr = (0x00, 0x80, 0x2f, 0x11, 0x4d, 0xac)
        self.fpga_version = '06300800'
        self.last_packet_index = None
        self.user_update_number = 0
        self.user_data_high = bytes()
        self.errors = ''
        self.user_data_low = bytes()
        self.ds_lcd_data = bytes()

    @property
    def battery(self):
        if self.battery_int == 0x37 and self.battery_frac == 0x37:
            return 0.0
        # convert from BCD to float
        bint = (self.battery_int>>4)*10 + (self.battery_int & 0xf)
        bfrac = (self.battery_frac>>4)*10 + (self.battery_frac & 0xf)
        return bint + bfrac / 100.0

    @battery.setter
    def battery(self, value):
        # convert from float to BCD
        bint = int(value)
        self.battery_int = (int(bint/10)<<4) + (bint % 10)
        bfrac = int((value - bint) * 100)
        self.battery_frac = (int(bfrac/10)<<4) + (bfrac % 10)

    def start_user(self):
        self.battery = 0

    def stop_user(self):
        self.battery_int = 0x37
        self.battery_frac = 0x37

    def is_code_running(self):
        return self.battery_int != 0x37 or self.battery_frac != 0x37

class EnhancedIOControl:
    pass

class EnhancedIOStatus:
    pass

_long_struct = struct.Struct('>L')
_status_struct = struct.Struct('>4B 4x H 6s 8s 6x H B')
_dashboard_base_data_struct = struct.Struct('>H 8B 8s')
_dashboard_reply_count_struct = struct.Struct('<H B')

class DriverStationState:
    def __init__(self):
        self.control = FRCCommonControlData()
        self.status = RobotStatusData()

    def packetize_command(self):
        """Create and return a DS->Robot command packet."""
        packet = bytearray(1024)
        self.control.pack_into(packet, 0)

        # generate CRC
        _long_struct.pack_into(packet, 0x3fc, crc32(packet) & 0xffffffff)
        return packet

    def unpacketize_status(self, packet):
        """Take a Robot->DS status packet and update the current state.
        Returns False if the packet did not have a correct CRC.
        """
        # check CRC
        if (crc32(packet[:0x3fc]+bytearray([0]*4)) !=
            _long_struct.unpack_from(packet, 0x3fc)[0]):
            return False

        # unpack data
        (control,
         battery_int,
         battery_frac,
         ds_digital_out,
         team_id,
         mac_addr,
         fpga_version,
         packet_index,
         user_update_number) = \
            _status_struct.unpack_from(packet, 0)

        # Check validity and timeliness.  Silently ignore if not current.
        # XXX: can control be different?
        if (team_id != self.control.team_id or
                packet_index != self.control.packet_index):
            return True

        # update status fields
        self.status.control.set(control)
        self.status.battery_int = battery_int
        self.status.battery_frac = battery_frac
        self.status.ds_digital_out[None] = ds_digital_out
        self.status.mac_addr = [x for x in mac_addr]
        self.status.fpga_version = fpga_version
        self.status.last_packet_index = packet_index
        self.status.user_update_number = user_update_number

        pos = 0x21
        for s in ["user_data_high", "errors", "user_data_low"]:
            slen = _long_struct.unpack_from(packet, pos)[0]
            pos += 4
            slen = max(0, min(0x3d8 - pos, slen))
            setattr(self.status, s, packet[pos:pos+slen])
            pos += slen

        self.status.ds_lcd_data = packet[0x400:]

        return True

    def packetize_dashboard(self):
        packet = bytearray(1018)

        team_hi, team_lo = divmod(self.control.team_id, 100)
        _dashboard_base_data_struct.pack_into(packet, 0,
                self.control.packet_index,
                int(self.control.ds_digital_in),
                int(self.status.ds_digital_out),
                self.status.battery_int,
                self.status.battery_frac,
                int(self.control.control),
                self.status.error,
                team_hi,
                team_lo,
                self.control.ds_version)
        self._reply_count_struct.pack_into(packet, 0x18,
                self.status.reply_count,
                self.status.user_update_number)
        pos = 0x1B
        for s in [self.status.user_data_high, self.status.errors,
                  self.status.user_data_low]:
            slen = max(0, min(0x3f2 - pos - 4, len(s)))
            struct.pack_into('>L %ds' % slen, packet, pos, slen, s)
            pos += 4 + slen

        _long_struct.pack_into(packet, 0x3f6, crc32(packet) & 0xffffffff)
        return packet

class RobotState:
    def __init__(self):
        self.control = FRCCommonControlData()
        self.status = RobotStatusData()
        self.dynamic = {}
        self.io_config = EnhancedIOStatus()

    def packetize_status(self):
        """Create and return a Robot->DS status packet."""
        packet = bytearray(STATUS_BASE_PACKET_SIZE+len(self.status.ds_lcd_data))
        _status_struct.pack_into(packet, 0,
                int(self.control.control),
                self.status.battery_int,
                self.status.battery_frac,
                int(self.status.ds_digital_out),
                self.control.team_id,
                bytes(self.status.mac_addr),
                self.status.fpga_version,
                self.control.packet_index,
                self.status.user_update_number)

        pos = 0x21
        for s in [self.status.user_data_high, self.status.errors,
                  self.status.user_data_low]:
            slen = max(0, min(0x3d8 - pos - 4, len(s)))
            struct.pack_into('>L %ds' % slen, packet, pos, slen, s)
            pos += 4 + slen

        packet[0x400:] = self.status.ds_lcd_data

        _long_struct.pack_into(packet, 0x3fc,
                               crc32(packet[:0x400]) & 0xffffffff)
        return packet

    def unpacketize_command(self, packet):
        """Take a DS->Robot command packet and update the current state.
        Returns False if the packet did not have a correct CRC.
        """
        # check CRC
        if (crc32(packet[:0x3fc]+bytearray([0]*4)) !=
            _long_struct.unpack_from(packet, 0x3fc)[0]):
            return False

        # unpack common control data
        self.control.unpack_from(packet, 0)

        # get dynamic control data
        pos = 0x73
        while pos < len(packet) and packet[pos] != 0:
            size = packet[pos]
            id = packet[pos+1]
            data = bytes(packet[pos+2:pos+2+size-1])
            self.dynamic[id] = data
            pos += size+1

        return True

class DashboardState:
    def update_from_packet(self, packet):
        self.control.team_id = team_hi * 100 + team_lo

FILTER=''.join([(len(repr(chr(x)))==3) and chr(x) or '.' for x in range(256)])

def hexdump(src, length=16):
    N=0; result=''
    while src:
        s,src = src[:length],src[length:]
        hexa = ' '.join(["%02X"%x for x in s])
        s = ''#s.translate(FILTER)
        result += "%04X   %-*s   %s\n" % (N, length*3, hexa, s)
        N+=length
    return result

if __name__ == "__main__":
    dss = DriverStationState()
    rs = RobotState()

    dss.control.packet_index = 0x15f7
    dss.control.team_id = 294
    dss.control.autonomous = False

    packet = dss.packetize_command()
    print(hexdump(packet))

    rs.unpacketize_command(packet)
    rs.status.battery = 11.8
    rs.status.ds_digital_out[None] = 0xAA
    rs.status.user_update_number = 0x55
    rs.status.user_data_high = b'UserDataHigh'
    rs.status.errors = b'ErrorData'
    rs.status.user_data_low = b'UserDataLow'

    packet = rs.packetize_status()
    print(hexdump(packet))

