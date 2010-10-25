rmdir /s /q dist
mkdir dist
mkdir dist\robot
mkdir dist\robot\lib
mkdir dist\robot\ni-rt
mkdir dist\robot\ni-rt\system

copy README.txt dist\
xcopy /i /e py dist\robot\py
xcopy /i /e Python\Lib dist\robot\lib\python3.1
xcopy /i /e samples dist\samples
copy PPC603gnu\RobotPy\NonDebug\RobotPy.out dist\robot\ni-rt\system\UserProgram.out

pause
