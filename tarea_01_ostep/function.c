#include <stdio.h>
#include <unistd.h>
#include <string.h>



void printReverseText(FILE *file,char str_aux)
{
	int i = -2;

	fseek(file,i,SEEK_END);
	while(ftell(file)  >= 0)
	{
			
		
		if(ftell(file) == 0)
		{
				
			fscanf(file,"%c", &str_aux);
        	       	printf("%c\n", str_aux);
			break;
			
		}else
		{

			fscanf(file,"%c", &str_aux);
	        	printf("%c", str_aux);
			i--;        	
                	fseek(file, i, SEEK_END);             

		}
	}
}
