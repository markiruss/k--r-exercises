REM install desktop development with C++ component in visual studio, and run this from a developer comand prompt

mkdir build\%1\%2
mkdir obj\%1\%2
cl %1\%2\%3.c /Fo: obj\%1\%2\ /link /out:build\%1\%2\%3.exe

.\build\%1\%2\%3.exe