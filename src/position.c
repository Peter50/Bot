#include <stdio.h>
#include <stdlib.h>

#include "vitesse.h"
#include "position.h"

struct sPosition{
	int x;
	int y;
};

Position initPosition(int x, int y){
	Position position=malloc(sizeof(struct sPosition));
	position->x=x;
	position->y=y;
	return position;
}

void detruirePosition(Position position){
	free(position);
}

int getPositionX(Position position){
	return position->x;
}

int getPositionY(Position position){
	return position->y;
}

Position ajouterPositionVitesse(Position position, Vitesse vitesse){
	Position position2=initPosition(getPositionX(position)+getVitesseX(vitesse),getPositionY(position)+getVitesseY(vitesse));
	return position2;
}

