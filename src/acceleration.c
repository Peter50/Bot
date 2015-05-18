#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"

struct sAcceleration{
	int x;
	int y;
};

Acceleration initAcceleration(int x, int y){
	Acceleration acceleration=malloc(sizeof(struct sAcceleration));
	acceleration->x=x;
	acceleration->y=y;
	return acceleration;
}

void detruireAcceleration(Acceleration acceleration){
	free(acceleration);
}

int getAccelerationX(Acceleration acceleration){
	return acceleration->x;
}

int getAccelerationY(Acceleration acceleration){
	return acceleration->y;
}

void jouerCoup(Acceleration acceleration){
	char action[100];
	sprintf(action,"%d %d",acceleration->x,acceleration->y);
	fprintf(stdout, "%s\n", action);
	fflush(stdout);
}

void afficherAcceleration(Acceleration acceleration){
    printf("x:%d y:%d\n",acceleration->x,acceleration->y);

}
