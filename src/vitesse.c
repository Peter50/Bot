#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"
#include "vitesse.h"

#define MAX_SPEED_SQUARE 25

struct sVitesse{
	int x;
	int y;
};

Vitesse initVitesse(int x,int y){
	Vitesse vitesse=malloc(sizeof(struct sVitesse));
	vitesse->x=x;
	vitesse->y=y;
	return vitesse;
}

void detruireVitesse(Vitesse vitesse){
	free(vitesse);
}

Vitesse ajouterVitesseAcceleration(Vitesse vitesse, Acceleration acceleration){
	Vitesse vitesse2=initVitesse(vitesse->x+getAccelerationX(acceleration),vitesse->y+getAccelerationY(acceleration));
	if(vitesse2->x * vitesse2->x + vitesse2->y * vitesse2->y > MAX_SPEED_SQUARE){
		vitesse2->x=0;
		vitesse2->y=0;
	}
	detruireVitesse(vitesse);
	return vitesse2;
}

int getVitesseX(Vitesse vitesse){
    return vitesse->x;
}

int getVitesseY(Vitesse vitesse){
    return vitesse->y;
}

void resetVitesse(Vitesse vitesse){
	vitesse->y=0;
	vitesse->x=0;
}

void afficherVitesse(Vitesse vitesse){
    printf("%d %d\n",vitesse->x,vitesse->y);
}
