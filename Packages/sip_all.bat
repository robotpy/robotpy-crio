@echo off

cd %~dp0

cd nivision
call sip_nivision.bat
cd ..

cd vision
call sip_vision.bat
cd ..

cd vision2009
call sip_vision2009.bat
cd ..

cd wpilib
call sip_wpilib.bat
cd ..
