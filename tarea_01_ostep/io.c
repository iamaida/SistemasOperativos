#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "function.h"

int main (int argc, char* argv[])
{

	FILE *file;
	char str_aux, *file_name;	
	
	if(argc != 2)
	{
		printf("Error: El programa debe recibir un argumento\n");
		return 1;
	}else
	{
		
		file_name = argv[1];
		
		//Validar la existencia del archivo
		if( access(file_name, F_OK ) != -1 ) 
		{
			file = fopen(file_name, "r");
			if (file != NULL)
			{	
				//Invocar función para imprimir el contenido del archivo de manera invertida
				printReverseText(file,str_aux);

			}else
			{
				printf("Error: El archivo no se puedo abrir\n");
				return 1;
			}


			fclose(file); //Cerrar Archivo
			
		} else 
		{
			printf("Archivo no encontrado!!\n");
			return 2;

		}

	}
		
		
	return 0;

}
