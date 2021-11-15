#include "turtle.h"
#include "parse.h"
#include "signal_handling.h"
#include "string_functions.h"

int empty_input(char *line)
{
    char *temp = line;
    temp = white_space_left_right(temp);
    if (strcmp(line, "") == 0 || strlen(temp) == 0)
        return 1;
    return 0;
}

int main(void)
{
    signal(SIGINT, signal_handler);
    char line[MAX_INPUT_SIZE];

    while (1)
    {

        printf("My-Shell$");
        bzero(line, MAX_INPUT_SIZE);
        gets(line);

        if (empty_input(line))
            continue;

        line[strlen(line)] = '\n'; //terminate the command with new line

        //Parse the string:
        parse_string(line);
    }

    return 0;
}
