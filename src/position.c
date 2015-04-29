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

Position ajouterPositionVitesse(Position position, Vitesse vitesse){
	return NULL;
}
