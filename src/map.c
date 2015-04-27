#include <stdio.h>
#include <stdlib.h>

#include "map.h"


struct sMap{

	char ** matrice;
	int ligne;
	int colonne;

}

Map initMap(int ligne, int colonne){
	int i=0;

	Map map=malloc(sizeof(struct sMap));
	map->ligne=ligne;
	map->colonne=colonne;
	map->matrice=malloc(sizeof(char *)*ligne);
	
	for(i=0;i<ligne;i++){
		map->matrice[i]=calloc(colonne,sizeof(char));
	}

	return map;
}

void chargerMap(Map map){

}
