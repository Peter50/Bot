#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"
#include "vitesse.h"
#include "position.h"
#include "voiture.h"

struct sVoiture{
	Position position;
	Vitesse vitesse;
	Voiture predecesseur;
	int carburant;
};

Voiture initVoiture(void){
	Voiture voiture=malloc(sizeof(struct sVoiture));
	voiture->position=initPosition(0,0);
	voiture->vitesse=initVitesse(0,0);
	voiture->predecesseur=NULL;
	voiture->carburant=0;
	return voiture;
}

void detruireVoiture(Voiture voiture){
	free(voiture);
}

Position deplacementVoiture(Voiture voiture){
	return ajouterPositionVitesse(voiture->position,voiture->vitesse);
}

Voiture ajouterVoitureAcceleration(Voiture voiture,Acceleration acceleration){
	Voiture voiture2=initVoiture();
	voiture2->vitesse=ajouterVitesseAcceleration(voiture->vitesse,acceleration);
	return voiture2;
}

void setPositionVoiture(Voiture voiture, Position position){
	voiture->position=position;
}