#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"
#include "vitesse.h"

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
	detruireVitesse(vitesse);
	return vitesse2;
}

int getVitesseX(Vitesse vitesse){
    return vitesse->x;
}

int getVitesseY(Vitesse vitesse){
    return vitesse->y;
}
