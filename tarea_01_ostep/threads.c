#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int counter = 0; 
int loops;
puerta door; 

void *worker(void *arg) {
    
	cerrar_puerta(door);
    	
	int i;
    	for (i = 0; i < loops; i++) {
		counter++;
    	}

   	abrir_puerta(door);
    	
	return NULL;
}

int main(int argc, char *argv[]) {

	crear_puerta(door);

	if (argc != 2) { 
		fprintf(stderr, "usage: threads <loops>\n"); 
		exit(1); 
	} 

	loops = atoi(argv[1]);
	pthread_t p1, p2;

	printf("Initial value : %d\n", counter);

	Pthread_create(&p1, NULL, worker, NULL); 
	Pthread_create(&p2, NULL, worker, NULL);
	Pthread_join(p1, NULL);
	Pthread_join(p2, NULL);
	printf("Final value   : %d\n", counter);
    
	destruir_puerta(door);

    return 0;
}

