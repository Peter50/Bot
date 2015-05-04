#ifndef _VOITURE_
#define _VOITURE_

typedef struct sVoiture * Voiture;

Voiture initVoiture(void);

void detruireVoiture(Voiture voiture);

Position deplacementVoiture(Voiture voiture);

Voiture ajouterVoitureAcceleration(Voiture voiture,Acceleration	acceleration);

void setPositionVoiture(Voiture voiture, Position position);

#endif
