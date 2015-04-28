#include <stdio.h>
#include <stdlib.h>

#include "map.h"


struct sMap{

	char ** matrice;
	int ligne;
	int colonne;
	int carburant;
	int boost;
};

Map initMap(int ligne, int colonne){
	int i=0;

	Map map=malloc(sizeof(struct sMap));
	map->ligne=ligne;
	map->colonne=colonne;
	map->matrice=malloc(sizeof(char *)*ligne);
	map->boost=5;

	for(i=0;i<ligne;i++){
		map->matrice[i]=calloc(colonne,sizeof(char));
	}

	return map;
}

Map chargerMap(void){

	FILE* info =fopen("Bot.log","w");
	char c;
	int ligne,colonne,carburant,i;
	fscanf(stdin,"%d %d %d",&colonne,&ligne,&carburant);

	Map map=initMap(ligne,colonne);

	while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
	for(i=0;i<ligne;i++){
		while(fread(&c,sizeof(char),1,stdin)==1 && c!='\n'){
			fprintf(info,"%c",c);
		}
		fprintf(info,"\n");
	}
	fflush(info);

	return map;
}
