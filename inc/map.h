#ifndef _MAP_
#define _MAP_

#include "position.h"
#include "voiture.h"

typedef struct sMap * Map;

typedef enum Case{
	VIDE,
	SABLE,
	ROUTE,
	ARRIVE,
}Case;

Map initMap(int ligne, int colonne);

Map chargerMap(void);

Map chergerFichierMap(char * fichier);

void sauverMap(Map map,char * fichier);

Case getCase(Map map,Position position);

int estValide(Map map,Position position);

Voiture simulation(Voiture voiture, Map map, Acceleration acceleration);

#endif
