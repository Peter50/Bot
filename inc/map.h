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
	J1,
	J2,
	J3,
}Case;

Map initMap(int ligne, int colonne);

Map chargerMap(void);

Map chargerFichierMap(char * fichier);

void sauverMap(Map map,char * fichier);

Case getCase(Map map,Position position);

int estValide(Map map,Position position);

Voiture simulation(Voiture voiture, Map map, Acceleration acceleration);

int estCheck(Voiture voiture,Map map);

int arrive(Voiture voiture, Map map);

#endif
