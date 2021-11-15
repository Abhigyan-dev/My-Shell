#include "redirection.h"
#include "parse.h"
#include "string_functions.h"

int check_redir(char *cmd)
{
    const char *result = strchr(cmd, '>');
    if (result == NULL)
        return 0;
    return 1;
}

void redirect(char *cmd, char *fileName)
{
    if (fork() == 0)
    {
        int file_descriptor_1 = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0777);

        if (file_descriptor_1 == -1)
        {
            printf("Error: File Descripter can't be opened.");
            return;
        }

        int file_descriptor_2 = dup2(file_descriptor_1, STDOUT_FILENO);

        close(file_descriptor_1);
        parse_string_3(cmd);
        close(file_descriptor_2);
        exit(0);
    }
    else
        wait(NULL);
}

void call_redirection(char *cmd)
{
    // If there is redirection(say cmd_a>b), separate command 'cmd_a' and file 'b',
    // go to redirect, change STDOUT to file b and then call parse_string_3(cmd_a) from there.

    char **token = tokenize(cmd, "Redirection");

    //Remove leading or tailing whitespaces from b.
    token[1] = white_space_left_right(token[1]);

    redirect(token[0], token[1]);
}