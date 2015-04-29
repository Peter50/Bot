#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "map.h"

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable)
{
	int valeur = accX*accX + accY*accY;
	valeur += (int)(sqrt(velX*velX+velY*velY)*3.0/2.0);
	if (dansSable) valeur += 1;
	return -valeur;
}

int main(int argn, char** argv){
	
	char c;
	Map map=chargerMap();
	sauverMap(map,"bot.log");
	int tour = 0;
	int accX = 0, accY = -1;
	int velX = 0, velY = 0;
	char action[100];
	
	while(!feof(stdin)){
		tour++;
		while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
		velX += accX;
		velY += accY;
		accY=-1;
		if(velY<-5){
			accY=0;
		}
		sprintf(action,"%d %d",accX,accY);
		fprintf(stdout, "%s\n", action);
		fflush(stdout);
	}


	return EXIT_SUCCESS;
} 
