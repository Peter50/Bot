#include <stdio.h>
#include <stdlib.h>

#include "acceleration.h"
#include "position.h"
#include "vitesse.h"
#include "voiture.h"
#include "map.h"

struct sMap{
	Case ** matrice;
	Acceleration * normal;
	Acceleration * booste;
	int ligne;
	int colonne;
	int carburant;
	int boost;
};

Map initMap(int ligne, int colonne){
	int i=0,j=0,k=0;

	Map map=malloc(sizeof(struct sMap));
	map->ligne=ligne;
	map->colonne=colonne;
	map->matrice=malloc(sizeof(Case *)*ligne);
	map->boost=5;
	map->carburant=0;

	for(i=0;i<ligne;i++){
		map->matrice[i]=calloc(colonne,sizeof(Case));
	}

	map->normal=malloc(sizeof(Acceleration)*9);
	for(i=-1;i<2;i++){
		for(j=-1;j<2;j++){
			map->normal[k]=initAcceleration(i,j);
			k++;
		}
	}

	map->normal=malloc(sizeof(Acceleration)*25);
	for(i=-2;i<3;i++){
		for(j=-2;j<3;j++){
			map->normal[k]=initAcceleration(i,j);
			k++;
		}
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

Map chargerFichierMap(char * fichier){

    char c=0;
    int ligne,colonne,carburant,i,j;
    FILE * file=fopen(fichier,"r");
	fscanf(file,"%d %d %d\n",&colonne,&ligne,&carburant);
	Map map=initMap(ligne,colonne);

	for(i=0;i<ligne;i++){
		j=0;
		while(c!='\n'){
            fscanf(file,"%c",&c);
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
	fprintf(file,"%d %d %d\n",map->ligne,map->colonne,map->carburant);
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

Case getCase(Map map,Position position){
	if(position == NULL){
		return VIDE;
	}
	if(getPositionX(position) >= map->ligne || getPositionX(position) < 0 || getPositionY(position) >= map->colonne || getPositionY(position) < 0){
		return VIDE;
	}
	return map->matrice[getPositionX(position)][getPositionY(position)];
}

int estValide(Map map,Position position){
	if(getCase(map,position)==VIDE){
		return 0;
	}
	return 1;
}



Voiture simulation(Voiture voiture,Map map,Acceleration acceleration){
	Voiture voiture2=ajouterVoitureAcceleration(voiture,acceleration);
	Position position2=deplacementVoiture(voiture2);
	if(estValide(map,position2)){
			setPositionVoiture(voiture,position2);
	}
	else{
		detruirePosition(position2);
	}

	return voiture;
}


