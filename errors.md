# Windows:

On Windows when running the following BASIC program:

```basic
10 PRINT HELLO WORLD
```

The program will run, then the interpreter will close with exit code `C0000005` which is a memory access violation.

When running the BASIC program on Windows:

```basic
10 GOSUB 15
15 PRINT HELLO
20 RETURN
```

The program will print "HELLO" twice followed by a `?RETURN WITHOUT GOSUB ERROR IN LINE` error followed by a crash with exit code `C0000409` which is a stack buffer overrun error.

# Linux:

On Linux when running the following BASIC program:

```basic
10 PRINT HELLO WORLD
```

The program will run (sometimes), then the interpreter will close with an `std:bad_alloc` error and sometimes the program will not run and will crash without having run the program and throws a segfault error. Interestingly, if the latter outcome occurs then the program does reach the stage of printing "HELLO WORLD" but simply doesn't, then procedces to crash on line 129.

On Linux when running the following BASIC program:

```basic
10 GOSUB 15
15 PRINT HELLO
20 RETURN
```

The program will print "HELLO" twice followed by a `?RETURN WITHOUT GOSUB ERROR IN LINE` error followed by a crash with an `std:bad_alloc` error.



Where any of these errors occur in Windows is unknown to me (although presumably the memory access violation occurs in the same place as the segfault although it has different results) and I do not known where the `std:bad_alloc` error occurs, because I'm not bothered to find out

[test]