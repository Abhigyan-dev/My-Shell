#ifndef __PIPE_H
#define __PIPE_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

int check_pipe(char *cmd);
void run_pipe(char *cmd1, char *cmd2);
void call_pipe(char *cmd);

#endif