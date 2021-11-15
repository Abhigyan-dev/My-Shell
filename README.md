# Hello Shell and Signals!

This is an implementation of shell in C using fork() and exec() system calls. The main program acts as the parent process while the command entered is parsed and executed in the foreground as a child process.

It supports the following functionalities:

1. All standalone built in commands of Linux (eg., `ls`,`cd`,`cat`,`echo`).
2. Output redirection using '`>`'. 
3. Piping using '`|`'.
4. Signal Handling for signals such as `SIGINT`.
5. Any number of linux commands separated by "`;;`" (eg., `ls ;; date ;; sleep 10`) can be executed one after the other independent of each other
