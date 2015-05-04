#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "acceleration.h"
#include "position.h"
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
	int x=0,y=0;
	Position position1,position2,position3;
	Acceleration acceleration;
	Map map=chargerMap();
	sauverMap(map,"bot.log");

	FILE * file=fopen("coupBot.log","w");

	int tour = 0;
	int accX = 0, accY = -1;
	int velX = 0, velY = 0;
	char action[100];
	
	while(!feof(stdin)){
		FILE * file=fopen("coupbot.log","w");
		tour++;
		fprintf(file,"%d ",tour);
		scanf("%d %d",&x,&y);
		fprintf(file,"%d %d ",x,y);
		position1=initPosition(x,y);	
		scanf("%d %d",&x,&y);
		fprintf(file,"%d %d ",x,y);
		position2=initPosition(x,y);
		scanf("%d %d",&x,&y);
		fprintf(file,"%d %d ",x,y);
		position3=initPosition(x,y);
		while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
		fprintf(file,"\n");
		fclose(file);

		velX += accX;
		velY += accY;
		accY=-1;
		if(velY<-5){
			accY=0;
		}
		acceleration=initAcceleration(accX,accY);
		jouerCoup(acceleration);
		detruireAcceleration(acceleration);
	}

	return EXIT_SUCCESS;
} 
