#ifndef _MAP_
#define _MAP_

typedef struct sMap * Map;

typedef enum Case{
	VIDE,
	SABLE,
	ROUTE,
	ARRIVE,
}Case;

Map initMap(int ligne, int colonne);

Map chargerMap(void);

void sauverMap(Map map,char * fichier);

#endif
