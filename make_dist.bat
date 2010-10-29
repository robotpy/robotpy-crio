rmdir /s /q dist
mkdir dist
mkdir dist\robot
mkdir dist\robot\lib
mkdir dist\robot\ni-rt
mkdir dist\robot\ni-rt\system

copy README.txt dist\
xcopy /i /e py dist\robot\py
xcopy /i /e RobotPy\Python\Lib dist\robot\lib\python3.1
xcopy /i /e samples dist\samples
copy RobotPy\PPC603gnu\RobotPy\NonDebug\RobotPy.out dist\robot\ni-rt\system\FRC_UserProgram.out

mkdir dist\robot\lib\python3.1\dyn-load
for /r Modules %%X in (*.out) do (copy %%X dist\robot\lib\python3.1\dyn-load)

for /r Packages %%X in (*.out) do (copy %%X dist\robot\lib\python3.1\site-packages)
for /r Packages %%X in (*.py) do (copy %%X dist\robot\lib\python3.1\site-packages)

pause
