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

Unzip the release .zip to a temporary directory.

Connect to your robot's IP with an FTP client (e.g. ``ftp://10.XX.YY.2/``,
where XXYY is your team number).  Copy all files and directories in the
distribution's ``robot`` directory to the root (top level) directory on the
robot.  Note: this will overwrite any UserProgram.out currently on the robot
with the Python interpreter.

.. vim: tw=80 et ts=3 sw=3 ft=rst fenc=utf-8
