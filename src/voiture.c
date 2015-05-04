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
	int rang;
	Acceleration coup;
};

Voiture initVoiture(void){
	Voiture voiture=malloc(sizeof(struct sVoiture));
	voiture->position=initPosition(0,0);
	voiture->vitesse=initVitesse(0,0);
	voiture->predecesseur=NULL;
	voiture->carburant=0;
	voiture->rang=0;
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
	voiture2->rang=voiture->rang++;
	voiture2->predecesseur=voiture;
	voiture2->vitesse=ajouterVitesseAcceleration(voiture->vitesse,acceleration);
	return voiture2;
}

void setPositionVoiture(Voiture voiture, Position position){
	detruirePosition(voiture->position);
	voiture->position=position;
}

void resetVitesseVoiture(Voiture voiture){
	resetVitesse(voiture->vitesse);
}

Position getPositionVoiture(Voiture voiture){
	return voiture->position;
}

void afficherVoiture(Voiture voiture){
    if(voiture){
        afficherPosition(voiture->position);
        afficherVitesse(voiture->vitesse);
        printf("%d %d\n",voiture->carburant,voiture->rang);
        afficherVoiture(voiture->predecesseur);
    }
}
