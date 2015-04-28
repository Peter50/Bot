#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "map.h"

/* Fonction permettant de calculer la consomation de carburant 
 * accX et accY accélération actuelle
 * velX et velY vitesse actuelle 
 * dansSable indique si la formule1 est sur une case de sable
 * retourne la variation de carburant
 *
 * Attention, même si le mouvement est illégal (donc pas de déplacement), il y a consomation de carburant
 * il faut donc éviter à tout prix de produire des mouvements illégaux
 */

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable)
{
	int valeur = accX*accX + accY*accY;
	valeur += (int)(sqrt(velX*velX+velY*velY)*3.0/2.0);
	if (dansSable) valeur += 1;
	return -valeur;
}

/* Pilote de base avec lecture carburant */
int main(int argn, char** argv){
	char c;
	Map map=chargerMap();
	int tour = 0;
	int accX = 0, accY = -1;
	int velX = 0, velY = 0;
	char action[100];
	while(!feof(stdin)){
		tour++;
		//Lecture des positions.
		while(fread(&c, sizeof(char), 1, stdin)==1 && c!='\n');
		// Pas de prise en compte du sable (pas de mémorisation de la carte)
		velX += accX;
		velY += accY;
		//Écriture de l'accélération.
		sprintf(action,"%d %d",accX,accY);
		fprintf(stdout, "%s\n", action);
		fflush(stdout); // Vidage du buffer nécessaire.
	}


	return EXIT_SUCCESS;
} 
