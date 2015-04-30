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
	int carburant; // Potentiellement facultatif
}

Voiture initVoiture(Voiture voiture){
	Voiture voiture=malloc(sizeof(struct sVoiture));
	voiture->position=initPosition();
	voiture->vitesse=initVitesse();
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
	voiture2->position=ajouterPositionVitesse(voiture2->vitesse,voiture->position);
	return voiture2;
}

void setPosition(Voiture voiture, Position position){
	voiture->position=position;
}
