#include "run_cmd.h"

void run_cmd(char *arr[])
{
    if (fork() == 0)
    {
        int out = execvp(arr[0], arr);    //Overtakes ,no need to exit.
        
        if(out==-1)
        {
            printf("Error: Command is not defined.\n");
            exit(0);
        }
    }
    else
        wait(NULL);
}