#ifndef __PARSE_H
#define __PARSE_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line, char *remove);
void parse_string_4(char *cmd);
void parse_string_3(char *cmd);
void parse_string_2(char *cmd);
void parse_string(char *cmd);

#endif