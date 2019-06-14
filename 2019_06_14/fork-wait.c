#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
Este programa en C debe imprimir lo siguiente:

Soy el hijo y mi identificador es getpid()
Soy el padre, mi identificados es getpid() y el de mi hijo es pid

**/


int main(int argc, char** argv){

	pid_t pid;
	pid = fork();
	if(pid == 0)
	{	
		//sleep(3);
		printf("Soy el hijo y mi identificador es %d\n",(int) getpid());
	}else
	if(pid > 0)
	{
		int status;
		pid_t pid2;
		printf("Soy el padre, mi identificador es %d y el de mi hijo es %d\n", (int) getpid(), (int)pid);
		pid2 = wait(NULL);
		printf("Termino mi hijo %d\n", (int) pid2);

	}

}
