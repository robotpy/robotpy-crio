rmdir /s /q dist
mkdir dist

rem RobotPy-Core distribution
mkdir dist\RobotPy-Core
mkdir dist\RobotPy-Core\robot
mkdir dist\RobotPy-Core\robot\lib
mkdir dist\RobotPy-Core\robot\ni-rt
mkdir dist\RobotPy-Core\robot\ni-rt\system

copy README-Core.txt dist\RobotPy-Core\
xcopy /i /e py dist\RobotPy-Core\robot\py
xcopy /i /e RobotPy\Python\Lib dist\RobotPy-Core\robot\lib\python3.1
copy RobotPy\PPC603gnu\RobotPy\NonDebug\RobotPy.out dist\RobotPy-Core\robot\ni-rt\system\FRC_UserProgram.out

mkdir dist\RobotPy-Core\robot\lib\python3.1\lib-dynload
for /r Modules %%X in (*.out) do (copy %%X dist\RobotPy-Core\robot\lib\python3.1\lib-dynload)

for /r Packages\sip %%X in (*.out) do (copy %%X dist\RobotPy-Core\robot\lib\python3.1\site-packages)

rem RobotPy-WPILib distribution
mkdir dist\RobotPy-WPILib
mkdir dist\RobotPy-WPILib\robot
mkdir dist\RobotPy-WPILib\robot\lib
mkdir dist\RobotPy-WPILib\robot\lib\python3.1
mkdir dist\RobotPy-WPILib\robot\lib\python3.1\site-packages

copy README-WPILib.txt dist\RobotPy-WPILib\

xcopy /i /e samples dist\RobotPy-WPILib\samples

for /r Packages\wpilib %%X in (*.out) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)
for /r Packages\wpilib %%X in (*.py) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)

for /r Packages\vision %%X in (*.out) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)
for /r Packages\vision %%X in (*.py) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)

for /r Packages\vision2009 %%X in (*.out) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)
for /r Packages\vision2009 %%X in (*.py) do (copy %%X dist\RobotPy-WPILib\robot\lib\python3.1\site-packages)


rem RobotPy-Utilities distribution
mkdir dist\RobotPy-Utilities
xcopy /i /e utilities dist\RobotPy-Utilities

rem Include the installer with the dist
copy utilities\installer\install.py dist\RobotPy-Core
copy utilities\installer\install.py dist\RobotPy-WPILib

pause
