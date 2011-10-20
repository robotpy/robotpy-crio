@echo off
if exist version goto haveversion

set errorlevel=0
set _my_=
for /f "usebackq tokens=1*" %%f in (`reg query HKCU\Software\TortoiseGit /v MSysGit`) do (set _my_=%%f %%g)
if %errorlevel% neq 0 goto notfound
if "%_my_%" == "" goto notfound

rem Using the shell script version (calling Git) ...
set _gitbin_=%_my_:*REG_SZ=%
for /f "tokens=*" %%a in ("%_gitbin_%") do set _gitbin_=%%a
echo %_gitbin_%
"%_gitbin_%\sh" VERSION-GEN.sh "%_gitbin_%"
exit /b

:notfound
rem Could not find Git ...
set _ver_=
for /f "usebackq tokens=2 delims==" %%a in (`%SystemRoot%\system32\find "DEF_VER=" ^<VERSION-GEN.sh`) do (set _ver_=%%a)
set _ver_=%_ver_:~1%
goto output

:haveversion
set /p _ver_=<version
goto output

:output
set /p _oldver_=<VERSION-FILE
set _oldver_=%_oldver_:~,-1%
if "%_ver_%" == "%_oldver_%" exit /b
echo %_ver_%
echo %_ver_% > VERSION-FILE
echo #define ROBOTPY_VERSION "%_ver_%" > VERSION-FILE.h

