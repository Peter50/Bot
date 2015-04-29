#include <stdio.h>
#include <stdlib.h>

#include "position.h"
#include "voiture.h"

struct sVoiture{
	Position position;
	Vitesse vitesse;
	Voiture predecesseur;
	int carburant; // Potentiellement facultatif
}

Voiture initVoiture(void){
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

void ajouterVoitureAcceleration(Voiture voiture,Acceleration acceleration){
	voiture->vitesse=ajouterVitesseAcceleration(voiture->vitesse	,acceleration);
	voiture->position=ajouterPositionVitesse(voiture->vitesse,voiture->position);
}
