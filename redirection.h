#ifndef __RED_H
#define __RED_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <fcntl.h>

int check_redir(char *cmd);
void redirect(char *printString, char *fileName);
void call_redirection(char *cmd);

#endif