#include "string_functions.h"

//Removes leading white spaces from left and proceeding white spaces from right of a string, and returns the new string.
char *white_space_left_right(char *str)
{
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0) // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

//Remove double quotes from string:
char *update_string_echo(char *cmd)
{
    for (int i = 0; i < strlen(cmd); i++)
    {
        if (cmd[i] == '"')
        {
            cmd[i] = ' ';
        }
    }
    return cmd;
}