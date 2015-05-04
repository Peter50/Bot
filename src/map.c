#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "acceleration.h"
#include "position.h"
#include "vitesse.h"
#include "voiture.h"
#include "map.h"

struct sMap{
	Case ** matrice;
	int ** check;
	Acceleration * normal;
	int nbNormal;
	Acceleration * booste;
	int nbBooste;
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
	map->nbNormal=9;
	for(i=-1;i<2;i++){
		for(j=-1;j<2;j++){
			map->normal[k]=initAcceleration(i,j);
			k++;
		}
	}

	map->normal=malloc(sizeof(Acceleration)*25);
	map->nbBooste=25;
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

    char c;
    int ligne,colonne,carburant,i,j;
    FILE * file=fopen(fichier,"r");
	fscanf(file,"%d %d %d\n",&colonne,&ligne,&carburant);
	Map map=initMap(ligne,colonne);
	map->carburant=carburant;
	for(i=0;i<ligne;i++){
		j=0;
		c='1';
		while(c!='\n'){
            fscanf(file,"%c",&c);
			printf("%c",c);
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
				case '1':
				map->matrice[i][j]=J1;
				break;
				case '2':
				map->matrice[i][j]=J2;
				break;
				case '3':
				map->matrice[i][j]=J3;
				break;
			}
			j++;
		}
		printf("\n");
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
					case J1:
					fprintf(file,"1");
					break;
					case J2:
					fprintf(file,"2");
					break;
					case J3:
					fprintf(file,"3");
					break;

				}
			}
			fprintf(file,"\n");
		}
	}
	fclose(file);
}

Case getCase(Map map,Position position){
	Case emplacement;
	if(position == NULL){
		return VIDE;
	}
	if(getPositionX(position) >= map->ligne || getPositionX(position) < 0 || getPositionY(position) >= map->colonne || getPositionY(position) < 0){
		return VIDE;
	}
	emplacement=map->matrice[getPositionX(position)][getPositionY(position)];
	if(emplacement==J1 || emplacement == J2 || emplacement == J3){
		return ROUTE;
	}
	return emplacement;
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
		resetVitesseVoiture(voiture2);
	}

	return voiture2;
}

Voiture listeVoiture(Map map,Voiture voiture){
	
	File file=initFile();
	Voiture voiture2=NULL;
	int i,end;

	enfiler(file,(void *)voiture);
	while(!(fileEstVide(file)) && end == 0){
		voiture=defiler(file);
		for(i=0;i<map->nbNormal;i++){
			voiture2=simulation(voiture,map,map->normal[i]);
			if(!(estCheck(voiture2,map))){
				enfiler(file,(void *)voiture2);
			}
			else{
				detruireVoiture(voiture2);
			}
		}
		if(arrive(voiture,map)){
			end=1;
		}
	}
	detruireFile(file);
	return voiture;
}

int estCheck(Voiture voiture, Map map){
	Position position=getPositionVoiture(voiture);
	if(map->check[getPositionX(position)][getPositionY(position)] == 0){
		map->check[getPositionX(position)][getPositionY(position)]=1;
		return 0;
	}

	return 1;
}

int arrive(Voiture voiture, Map map){
	Position position=getPositionVoiture(voiture);
	if(map->matrice[getPositionX(position)][getPositionY(position)] == ARRIVE){
		return 1;
	}
	return 0;
}

