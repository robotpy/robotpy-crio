#!/usr/bin/env python

# Copyright (c) Robert Blair Mason Jr. (rbmj) rbmj@verizon.net
# see LICENSE for license information.

import socket
import sys
import threading
import atexit
import time

#allow import in both python 2.x and 3.x
try:
    from Queue import Queue, Empty
except ImportError:
    from queue import Queue, Empty

#ports
UDP_IN_PORT=6666
UDP_OUT_PORT=6668

#set up recieving socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind( ('',UDP_IN_PORT) )

#set up sending socket - use separate socket to avoid race condition
out = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
out.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
out.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
out.bind( ('',UDP_OUT_PORT) ) #bind is necessary for escoteric reasons stated on interwebs

#set up atexit handler to close sockets
def atexit_func():
    sock.close()
    out.close()

atexit.register(atexit_func)

#set up threads to emulate non-blocking io
#thread-level emulation required for compatibility with windows
stdin_queue = Queue()
sock_queue = Queue()

def enqueue_output_file(f, q):
    for line in iter(f.readline, b''): #thanks to stackoverflow
        q.put(line)

def enqueue_output_sock(s, q):
    while True:
        q.put(s.recv(4096))

stdin_reader = threading.Thread(target = enqueue_output_file, args = (sys.stdin, stdin_queue))
sock_reader = threading.Thread(target = enqueue_output_sock, args = (sock, sock_queue))
stdin_reader.daemon = True
sock_reader.daemon = True
stdin_reader.start()
sock_reader.start()


if sys.version_info[0] == 2:
    def print_str(s):
        sys.stdout.write(s)
        
    def send_msg(msg):
        out.sendto(line, ('255.255.255.255', UDP_OUT_PORT))
else:
    def print_str(s):
        sys.stdout.write(str(s, 'utf-8'))

    def send_msg(msg):
        out.sendto(line.encode('utf-8'), ('255.255.255.255', UDP_OUT_PORT))

#main loop
while True:
    try: msg = sock_queue.get_nowait()
    except Empty:
        pass # no output
    else:
        print_str(msg)
    try: line = stdin_queue.get_nowait()
    except Empty:
        pass # no input
    else:
        send_msg(line)
    time.sleep(0.05)

