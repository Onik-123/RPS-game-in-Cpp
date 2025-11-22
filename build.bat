@echo off
REM Set up the Visual Studio environment (adjust path if needed)
call "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Building static libraries...

REM Compile and create static library for player
cl /c /EHsc player.cpp
lib /OUT:player.lib player.obj

REM Compile and create static library for computer
cl /c /EHsc computer.cpp
lib /OUT:computer.lib computer.obj

REM Compile and create static library for engine
cl /c /EHsc engine.cpp
lib /OUT:engine.lib engine.obj

echo Compiling main.cpp...
cl /c /EHsc main.cpp
if errorlevel 1 exit /b %errorlevel%

echo Linking everything...
link main.obj player.lib computer.lib engine.lib /OUT:rps.exe
if exist rps.exe (
    echo Build successful! Run rps.exe to play.
) else (
    echo Build failed!
)

exit /b %errorlevel%

