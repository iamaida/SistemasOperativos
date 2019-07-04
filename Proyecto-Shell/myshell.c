#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char* myCommand(char* command, char* subcommand);
void interpretCommand(char *command,char* args[]);
void readCommand(char *command);
int countSpaces(char* command);


int main()
{

	pid_t value; 
	char* command; 
	char *args[20];
	//Reserva memoria de manera dinamica
	command = (char*) malloc(sizeof (char *));
	int cont=0;
	
			
	do{
		
		readCommand(command);//Invoca función para leer el comando
		
		if (strcmp("quit", command) == 0)//Valida si el comando no es quit
		{
			break;
		}
		
		interpretCommand(command, args);//Invoca función para interpretar comando
		
		value = fork();
		if(value == 0)
		{
			//Proceso hijo
			execvp(args[0], args);//Invoca una llamada al sistema de la famila exec para ejecutar los comandos
			printf("Esto no deberia imprimirse");

		}else
		{
			//Proceso padre
			wait(NULL);//Espera hasta que su hijo finalice
			
		}
			
		//Contador provicional
		cont ++;
		

	}while(cont<10);

	//Liberación de memoria
	free(command);
	
	
	return 0;	
}


char* myCommand(char* command, char* subcommand)
{
	//Recorrer comando
	int i=0;
	int j=0;
	int contador=0;
	char *aux;
	aux = (char*) malloc(sizeof (char *));
	while( i < strlen(command) && command[i] != '\n')
	{
			
		if (command[i] == 32)
		{
			
			contador++;
		}

		if (contador == 0)
		{
			aux[i]=command[i]; //Revisar 
		}else
		{
			command[j]=command[i+1];
			
			j++;
		}
	
			i++;
	}
	strcpy(subcommand, aux);
	free(aux);
	return subcommand;
	
}

int countSpaces(char* command)
{
	//Recorrer comando
	int i=0;
	int contador=0;
	while( i < strlen(command) && command[i] != '\n')
	{
			
		if (command[i] == 32)
		{
			
			contador++;
		}

		i++;
	}
	return contador;
}
void interpretCommand(char *command, char* args[])
{
	char * subcommand;
	subcommand = (char*) malloc(sizeof (char *)); 
	int counter = countSpaces(command);//Invocación de la función

	for(int j=0; j< (counter + 1); j++)
	{
		//Permite strdup duplicar un string
		args[j] =strdup(myCommand(command, subcommand));//Invoca a la función 

	}
	args[counter+1] = NULL;
	free(subcommand);
}

void readCommand(char *command)
{

	printf("prompt>");
	//Leer comando
	fgets(command, MAX_SIZE, stdin);
	//Eliminar la nueva linea final si la hay
	if ((strlen(command) > 0) && (command[strlen (command) - 1] == '\n'))
       	{
		command[strlen (command) - 1] = '\0';
	}

}
