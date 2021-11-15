#include "parse.h"
#include "run_cmd.h"
#include "redirection.h"
#include "cd.h"
#include "pipe.h"
#include "string_functions.h"

char **tokenize(char *line, char *remove)
{
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
    int i, tokenIndex = 0, tokenNo = 0;

    for (i = 0; i < strlen(line); i++)
    {

        char readChar = line[i];

        if (strcmp(remove, "White Space") == 0)
        {
            if (readChar == ' ' || readChar == '\n' || readChar == '\t')
            {
                token[tokenIndex] = '\0';
                if (tokenIndex != 0)
                {
                    tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                    strcpy(tokens[tokenNo++], token);
                    tokenIndex = 0;
                }
            }
            else
            {
                token[tokenIndex++] = readChar;
            }
        }
        else if (strcmp(remove, "Redirection") == 0)
        {
            if (readChar == '>' || readChar == '\n')
            {
                token[tokenIndex] = '\0';
                if (tokenIndex != 0)
                {
                    tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                    strcpy(tokens[tokenNo++], token);
                    tokenIndex = 0;
                }
            }
            else
            {
                token[tokenIndex++] = readChar;
            }
        }
        else if (strcmp(remove, "Pipe") == 0)
        {
            if (readChar == '|' || readChar == '\n')
            {
                token[tokenIndex] = '\0';
                if (tokenIndex != 0)
                {
                    tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                    strcpy(tokens[tokenNo++], token);
                    tokenIndex = 0;
                }
            }
            else
            {
                token[tokenIndex++] = readChar;
            }
        }
    }

    if (tokenIndex != 0)
    {
        tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
        strcpy(tokens[tokenNo++], token);
        tokenIndex = 0;
    }

    free(token);
    tokens[tokenNo] = NULL;
    return tokens;
}

void parse_string_4(char *cmd)
{
    //Remove white spaces
    char **arr = tokenize(cmd, "White Space");

    if (strcmp(arr[0], "cd") == 0)
    {
        //If command is "cd"
        call_cd(arr);
    }
    else if (strcmp(arr[0], "echo") == 0)
    {
        //If command is "echo"
        char *new_cmd;
        new_cmd = update_string_echo(cmd);
        char **arr2 = tokenize(new_cmd,"White Space");
        run_cmd(arr2);
    }
    else if (strcmp(arr[0], "exit") == 0)
    {
        //If command is "exit"
        exit(0);
    }
    else
    {
        //Else run the given command using "run_cmd"
        run_cmd(arr);
    }
}

void parse_string_3(char *cmd)
{
    //Extract pipe from command:
    if (check_pipe(cmd) == 1)
    {
        call_pipe(cmd);
    }
    else
        parse_string_4(cmd);
}

void parse_string_2(char *cmd)
{
    //Extract redirection from the commands:

    if (check_redir(cmd) == 1)
    {
        call_redirection(cmd);
    }
    else
        parse_string_3(cmd);
}

void parse_string(char *cmd)
{
    //Extract the commands by semi-colon
    char *rest = cmd;
    char *save_ptr;
    char *token = strtok_r(rest, ";;", &save_ptr);

    while (token != NULL)
    {
        parse_string_2(token);
        token = strtok_r(NULL, ";;", &save_ptr);
    }
}
