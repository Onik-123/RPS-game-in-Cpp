@echo off
echo Compiling project...

g++ -c player.cpp -o player.o
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

g++ -c computer.cpp -o computer.o
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

g++ -c engine.cpp -o engine.o
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

g++ -c main.cpp -o main.o
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

g++ player.o computer.o engine.o main.o -o rps.exe
if %ERRORLEVEL% equ 0 (
    echo Build successful! Run rps.exe to play.
) else (
    echo Build failed!
)

exit /b %ERRORLEVEL%