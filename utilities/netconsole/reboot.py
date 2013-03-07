#!/usr/bin/env python
#
# Reboots the cRio via NetConsole
#

import socket

# ports
UDP_IN_PORT=6666
UDP_OUT_PORT=6668

out = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
out.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
out.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
out.bind( ('',UDP_OUT_PORT) ) # bind is necessary for escoteric reasons stated on interwebs

def reboot_cRio():
    '''Send the reboot command to any cRios connected on the network'''
    out.sendto(b'\nreboot\n', ('255.255.255.255', UDP_OUT_PORT))
    
if __name__ == '__main__':
    reboot_cRio()
