#include <stdio.h>
#include <stdlib.h>

#include "position.h"

struct sPosition{
	int x;
	int y;
}

Postion initPosition(int x, int y){
	Position position=malloc(sizeof(struct sPosition));
	position->x=x;
	position->y=y;
	return position;
}

void detruirePosition(Position position){
	free(position);	
}