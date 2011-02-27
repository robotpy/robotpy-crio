*************************************************
  RobotPy: Python for FRC cRIO Robot Controller
*************************************************

About RobotPy Utilities
========================

These are a distribution of various utilities that will hopefully make
using RobotPy a little bit easier for you. Some utilities will require
Python 3 on your development machine to run the scripts, and some of 
them are intended to be run on the cRIO.

A brief description of the utilities currently included:

WinPDB:
    
    A modified version of WinPDB (http://winpdb.org/) that has been 
    patched to work correctly on RobotPy. WinPDB is a platform 
    independent remote python debugger that you can use to remotely
    debug python programs on your robot. 
    
    See winpdb/README-FRC.txt for more details
    
RIPShell:

    Provides an interactive python interpreter that runs on the robot 
    that is accessible over the network. 
    
    To use: copy the included ripshell/* files to the robot, and reset
    the robot. Then run ripshell.py [robot ip] to connect to the shell
    and execute python commands on the robot remotely. 

installer:

    An installer you can use to upload your robot files to the robot
    without needing to use an FTP client


Installation
=============

Extract the files to a directory and use them as directed in their
respective README files.

For easier usage of the utility packages, you may want to copy the 
following files to the /lib/python31/site-packages directory on your
robot:

    ripshell/ripshell.py
    winpdb/rpdb2.py
