#ifndef _VITESSE_
#define _VITESSE_

#include "acceleration.h"

typedef struct sVitesse * Vitesse;

Vitesse initVitesse(int x, int y);

void detruireVitesse(Vitesse vitesse);

Vitesse ajouterVitesseAcceleration(Vitesse vitesse, Acceleration acceleration);

int getVitesseX(Vitesse vitesse);

int getVitesseY(Vitesse vitesse);

void resetVitesse(Vitesse vitesse);

void afficherVitesse(Vitesse vitesse);

#endif
