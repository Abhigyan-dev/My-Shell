#include "pipe.h"
#include "parse.h"

int check_pipe(char *cmd)
{
    const char *result = strchr(cmd, '|');
    if (result == NULL)
        return 0;
    return 1;
}

void run_pipe(char *cmd1, char *cmd2)
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        printf("Error Occured: Pipe can't be opened.");
        return;
    }
    int pid1, pid2;

    //Create Child Process : 1
    pid1 = fork();
    if (pid1 < 0)
    {
        printf("Error Occured: Fork can't be done.");
        return;
    }
    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        parse_string_4(cmd1);
        exit(0);
    }

    //Create Child process : 2
    pid2 = fork();
    if (pid2 < 0)
    {
        printf("Error Occured: Fork can't be done.");
        return;
    }

    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        parse_string_4(cmd2);
        exit(0);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void call_pipe(char *cmd)
{
    char **token = tokenize(cmd, "Pipe");
    run_pipe(token[0], token[1]);
}