#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"
#include "vitesse.h"
#include "voiture.h"
#include "map.h"

struct sMap{
	Case ** matrice;
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
	map->matrice=malloc(sizeof(Case *)*ligne);
	map->boost=5;
	map->carburant=0;
	
	for(i=0;i<ligne;i++){
		map->matrice[i]=calloc(colonne,sizeof(Case));
	}

	return map;
}

Map chargerMap(void){
	char c;
	int ligne,colonne,carburant,i,j;
	fscanf(stdin,"%d %d %d",&colonne,&ligne,&carburant);

	Map map=initMap(ligne,colonne);

	while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
	for(i=0;i<ligne;i++){
		j=0;
		while(fread(&c,sizeof(char),1,stdin)==1 && c!='\n'){
			switch(c){
				case '.':
				map->matrice[i][j]=VIDE;
				break;
				case '#':
				map->matrice[i][j]=ROUTE;
				break;
				case '=':
				map->matrice[i][j]=ARRIVE;
				break;
				case '~':
				map->matrice[i][j]=SABLE;
				break;
			}
			j++;
		}
	}
	return map;
}

void sauverMap(Map map,char * fichier){
	int i,j;
	FILE * file=fopen(fichier,"w");
	fprintf(file,"Map %d %d :\n",map->ligne,map->colonne);
	if(map){
		for(i=0;i<map->ligne;i++){
			for(j=0;j<map->colonne;j++){
				switch(map->matrice[i][j]){
					case VIDE:
					fprintf(file,".");
					break;
					case ROUTE:
					fprintf(file,"#");
					break;				
					case SABLE:
					fprintf(file,"~");
					break;					
					case ARRIVE:
					fprintf(file,"=");
					break;
				}
			}
			fprintf(file,"\n");
		}
	}
	fclose(file);
}

Voiture simulation(Voiture voiture,Map map,Acceleration acceleration){
	return NULL;
}
