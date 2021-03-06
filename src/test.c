#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "pile.h"
#include "voiture.h"
#include "map.h"

int main(int argn, char** argv){
    Map map=chargerFichierMap("misc/test_teleportation.txt");
	sauverMap(map,"log/test_teleportation.txt");
	Voiture voiture=initVoiture();
	setPositionVoiture(voiture,getPosition(map));
	Voiture voiture2=listeVoiture(map,voiture);
	afficherVoiture(voiture2);
	printf("Liste ----------------------------------------\n");
	afficherVoitureRecursif(voiture2);
    return 0;
}
