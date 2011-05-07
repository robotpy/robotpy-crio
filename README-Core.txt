*************************************************
  RobotPy: Python for FRC cRIO Robot Controller
*************************************************

:Author: Peter Johnson, FRC Team 294
:Copyright: Copyright © 2010, Peter Johnson, Ross Light

About RobotPy
===============

`RobotPy`_ is a distribution of `Python`_ intended to be used for the `FIRST
Robotics Competition`_.  Teams can use this to write their robot code in
Python, a powerful dynamic programming language.

.. _RobotPy: http://firstforge.wpi.edu/sf/projects/robotpy
.. _Python: http://www.python.org/
.. _FIRST Robotics Competition: http://www.usfirst.org/

Installation
==============

To write robot code, you'll want to install both the Core and WPILib
distributions.  The Core distribution contains only the Python interpreter and
standard libraries, while the WPILib distribution contains the Python WPILib
library typically used for interfacing to robot functions.

Unzip the release .zip to a temporary directory.

The preferred installation method is to run install.py.  This requires a local
(Windows) installation of Python.  Note: this will overwrite any
UserProgram.out currently on the robot with the Python interpreter.

Alternatively, you can use any FTP client (e.g. FileZilla) to install.  Connect
to your robot's IP with an FTP client (e.g. ``ftp://10.XX.YY.2/``, where XXYY
is your team number).  Copy all files and directories in the distribution's
``robot`` directory to the root (top level) directory on the robot.

.. vim: tw=80 et ts=3 sw=3 ft=rst fenc=utf-8
