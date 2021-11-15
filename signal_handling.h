#ifndef __SIGHANDLE_H
#define __SIGHANDLE_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

void signal_handler(int signal_number);
#endif