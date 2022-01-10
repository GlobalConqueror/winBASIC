# COMMODORE BASIC V2 FOR WINDOWS

A Windows interpreter for Commodore 64 BASIC v2

If compiling for Windows use:
  Clang: clang++ -pthread -std=c++17 -o BASIC.exe BASIC.cpp
  MSVC / cl.exe: cl BASIC.cpp
  
If compiling with Clang on Linux (I have not tried other operating systems or gcc) then upon trying to run a program you might be greeted with a segfault which I cannot determine the origin of _OR_ the program will run and, upon finishing the program, will throw an `std:bad_alloc` error in place of the `C0000005` or `3221226505` exit codes thrown on Windows machines.