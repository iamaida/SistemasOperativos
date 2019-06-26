/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto8.c
 * Fecha de creacion: 26-Junio-2019
 * Fecha ultima modificacion: 26-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define MSGSIZE 30 

//Prototipo de la función
void myfork(pid_t pid_child1, pid_t pid_child2);

//Función principal
int main()
{
	
	pid_t pid_child1, pid_child2;
	
	
	myfork(pid_child1, pid_child2);//Invocación  de la función

	return 0;
} 

//Definición de la función
void myfork(pid_t pid_child1, pid_t pid_child2)
{
	
	int fds[2]; //fds: fds[0] file descriptor lectura - fds[1] file descriptor escritura
	char *message;
	char inbuf[MSGSIZE];

	if (pipe(fds) < 0)
	{
		//Error
		perror("Error: En la apertura del pipe!!");
		exit(1);//Terminar
	}else
	{
		pid_child1 = fork(); //Crear primer proceso hijo
	
		if (pid_child1 < 0) 
		{
			//Error
			perror("Error: La creación del proceso hijo no fue exitosa!!");
			exit(1);//Terminar
		}
		else if(pid_child1 == 0) 
		{
	
			//Primer proceso hijo
			printf("%d: Soy el primer proceso hijo\n", (int)getpid());

			message = "Hola, Buenos dias";

			//Escribir en el pipe
			if (write(fds[1],message,MSGSIZE) < 0) 
			{ 
				perror("w1"); 
				exit(1);
			}else
			{
				close(fds[1]);
				printf("%d: Escribe en el pipe --> %s\n", (int)getpid(), message);
			}

				
		}else
		{
		
			printf("%d: Soy el proceso padre, el pid de mi primer hijo es %d\n", (int)getpid(), (int)pid_child1);
			wait(NULL);
			pid_child2 = fork(); //Crear segundo proceso hijo

			if (pid_child2 < 0) 
			{
				//Error
				perror("Error: La creación del proceso hijo no fue exitosa!!");
				exit(1);//Terminar
			}
			else if(pid_child2 == 0) 
			{
	
				//Segundo proceso hijo
				printf("%d: Soy el segundo proceso hijo\n", (int)getpid());

				if (read(fds[0],inbuf, MSGSIZE) < 0) 
				{ 	
					perror("r1"); 
					exit(1); 
				}else
				{
					close(fds[0]);
					printf("%d: Lee del pipe --> %s\n", (int)getpid(), inbuf);
				}
	
		
			}else
			{
				wait(NULL);
				printf("%d: Soy el proceso padre, el pid de mi segundo hijo es %d\n", (int)getpid(), (int)pid_child2);
		
			}
		
		}
	}
	
	
			
}
