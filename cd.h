#ifndef __CD_H
#define __CD_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

int parse_cd(char *arr[]);
void cd(char *pth);
void call_cd(char **arr);

#endif