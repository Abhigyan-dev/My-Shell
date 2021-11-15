#include "cd.h"

int parse_cd(char *arr[])
{
    int cnt = 0;
    for (int i = 0; arr[i] != NULL; i++)
    {
        cnt++;
    }

    if (cnt == 2)
        return 1;
    else
        return -1;
}

void cd(char *pth)
{
    int out = chdir(pth);

    if (out == -1)
    {
        printf("Directory does not exist.\n");
    }
}

void call_cd(char **arr)
{
    //Check if command is cd:
    int ret = parse_cd(arr);

    if (ret == -1)
        printf("Please enter a valid commnad\n");
    else
        cd(arr[1]);
}