# COMMODORE BASIC V2 FOR WINDOWS

A Windows interpreter Commodore 64 BASIC v2

If compiling for Windows use:
  Clang: clang++ -pthread -std=c++17 -o BASIC.exe BASIC.cpp
  MSVC / cl.exe: cl BASIC.cpp
  
If compiling with Clang on Linux (I have not tried other operating systems or gcc) then upon trying to run a program you will be greeted with a segfault which I cannot find the origin of and am too lazy to fix seeing as I exclusivly use Windows
