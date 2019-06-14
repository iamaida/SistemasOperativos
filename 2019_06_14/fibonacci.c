
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "solucion.h"

/**
En este programa el proceso hijo calcula el fibonacci de un número y ese número
lo recibe  el padre, lo multiplica por 100 y el padre imprime el resultado.
**/


int main(int argc, char** argv){

	pid_t pid;
	int n = 20;
	pid = fork();

	if(pid < 0)
	{	
		fprintf(stderr, "fork ha fallado!!\n");
		return 1;
	}else
	if(pid == 0)
	{
		
		printf("%d: Proceso hijo\n", (int) getpid());
		int fib = fibonacci(n);
		guardarEntero("archivo", fib);
		printf("Fibonacci(%d): %d\n", n, fib);		

	}else
	{
		wait(NULL);
		int num =leerEntero("archivo");
		num = num * 100;
		printf("%d: Proceso padre\n", (int) getpid());
		printf("Resultado = %d\n", num);
		
	}

	return 0;

}
