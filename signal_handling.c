#include "signal_handling.h"

void signal_handler(int signal_number) {
	
	if(signal_number==SIGINT)
	{
        // Do nothing
        printf("SIGINT received and ignored\n");
        printf("My-Shell$");
        fflush(0);
        return;
    }
}
