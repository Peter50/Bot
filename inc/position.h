#ifndef _POSITION_
#define _POSITION_

#include "vitesse.h"

typedef struct sPosition * Position;

Position initPosition(int x, int y);

void detruirePosition(Position position);

int getPositionX(Position position);

int getPositionY(Position position);

Position ajouterPositionVitesse(Position position, Vitesse vitesse);

#endif
