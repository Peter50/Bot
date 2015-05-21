#ifndef _VOITURE_
#define _VOITURE_

#include "acceleration.h"
#include "vitesse.h"
#include "position.h"

typedef struct sVoiture * Voiture;

Voiture initVoiture(void);

void detruireVoiture(Voiture voiture);

Position deplacementVoiture(Voiture voiture);

Voiture ajouterVoitureAcceleration(Voiture voiture,Acceleration	acceleration);

void setPositionVoiture(Voiture voiture, Position position);

void resetVitesseVoiture(Voiture voiture);

Position getPositionVoiture(Voiture voiture);

void afficherVoiture(Voiture voiture);

void afficherVoitureRecursif(Voiture voiture);

#endif
