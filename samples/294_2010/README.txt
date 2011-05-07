*********************************
  Team 294 2010 Translated Code
*********************************

This is a near-direct translation of Team 294's (Beach Cities Robotics)
championship C++ robot code from the 2010 season (Breakaway).  294 was the #1
seed in Newton division that year and went on to win the championship along
with teams 67 and 177.

Robot Description
===================

* Dropped center, 4 CIM drivetrain, with shifters
* 2xFP kicker gearbox with wire rope winch to pull back elastic kicker
* Ratchet to lock kicker position and allow for winch to unwind prior to kick
  with ratchet release
* Pincher intake (single roller driven by CIM), with clutch to prevent stall

CAN bus was used for all motor control and current sensing on the intake.
Current sensing was used to determine ball possession.

Sensors:
* Current sense (via CAN) on intake
* Left and right drivetrain encoders
* Encoder on kicker gearbox
* Limit switches on kicker action: 1 to zero encoder, 1 as safety on backstop

Code Organization
===================

* Config.py: motor/sensor connections, global settings, PID controllers
* Kicker.py: class to manage kicker, including winch and ratchet actions
* robot.py: main robot class, teleop code
* Autonomous.py: autonomous selection and state machine; the most common modes
                 used were modes 1 and 8 (kicking from far zone)
* DualSpeedController.py: Utility class to drive two speed controllers as one
* EncoderSource.py: Map encoder value to PIDGet() for PID position control
* WinchOutput.py: Limited PID setter that checks safety limit switch on backstop

.. vim: tw=80 et ts=3 sw=3 ft=rst fenc=utf-8
