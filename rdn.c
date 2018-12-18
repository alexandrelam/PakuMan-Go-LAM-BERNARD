#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

int main(void){
	int i = 0;
	int nombre_aleatoire = 0;
	for(i=0; i<5; i++){
		nombre_aleatoire = rand() % 20;
		printf("%d ",nombre_aleatoire);
	}
	return 0;
}
