*************************************************
  RobotPy: Python for FRC cRIO Robot Controller
*************************************************

:Author: Peter Johnson, FRC Team 294
:Author: Dustin Spicuzza, FRC Team 2423/1418
:Copyright: Copyright © 2010, Peter Johnson, Ross Light, Dustin Spicuzza


About RobotPy
===============

`RobotPy`_ is a distribution of `Python`_ intended to be used for the `FIRST
Robotics Competition`_.  Teams can use this to write their robot code in
Python, a powerful dynamic programming language.

Warning: This release does not support the roboRIO! Go to 
https://github.com/robotpy/robotpy-wpilib to get the latest roboRIO release of
RobotPy.

.. _RobotPy: http://robotpy.github.io
.. _Python: http://www.python.org/
.. _FIRST Robotics Competition: http://www.usfirst.org/

Installation
==============

Unzip the release .zip to a temporary directory.

The preferred installation method is to run install.py.  This requires a local
(Windows) installation of Python.

Alternatively, you can use any FTP client (e.g. FileZilla) to install.  Connect
to your robot's IP with an FTP client (e.g. ``ftp://10.XX.YY.2/``, where XXYY
is your team number).  Copy all files and directories in the distribution's
``robot`` directory to the root (top level) directory on the robot.

You must have your cRio/cRio-II imaged with the latest FRC image (v52). For
more information, see the following page:

https://usfirst.collab.net/sf/wiki/do/viewPage/projects.thunder_crio_c_tools/wiki/HomePage#section-HomePage-OtherCRIOInformation

Getting started
===============

The RobotPy documentation site has some content on how to get started with
RobotPy.

http://robotpy.readthedocs.org

Development tools
=================

See the utilities directory for useful development tools that will make
your RobotPy development experience easier. 

The pyfrc python package is a recommended development package that provides
unit testing and other capabilities for your robot code. 

	https://github.com/robotpy/pyfrc


WPILib License
================
Copyright (c) 2009 FIRST
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the FIRST nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY FIRST AND CONTRIBUTORS``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY NONINFRINGEMENT AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL FIRST OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

.. vim: tw=80 et ts=3 sw=3 ft=rst fenc=utf-8
