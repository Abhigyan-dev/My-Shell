
CFLAGS = -g -Wall

my_shell: turtle.o parse.o run_cmd.o redirection.o signal_handling.o cd.o pipe.o string_functions.o
	gcc -o my_shell $(CFLAGS) turtle.o parse.o run_cmd.o redirection.o signal_handling.o cd.o pipe.o string_functions.o

clean:
	rm -f *.o my_shell

# DONOT USE THESE RULES DIRECTLY
turtle.o: turtle.c turtle.h
	gcc $(CFLAGS) -c turtle.c

parse.o: parse.c parse.h
	gcc $(CFLAGS) -c parse.c	

run_cmd.o: run_cmd.c run_cmd.h
	gcc $(CFLAGS) -c run_cmd.c

redirection.o: redirection.c redirection.h
	gcc $(CFLAGS) -c redirection.c

signal_handling.o: signal_handling.c signal_handling.h
	gcc $(CFLAGS) -c signal_handling.c

cd.o: cd.c cd.h
	gcc $(CFLAGS) -c cd.c

pipe.o: pipe.c pipe.h
	gcc $(CFLAGS) -c pipe.c

string_functions.o: string_functions.c string_functions.h
	gcc $(CFLAGS) -c string_functions.c