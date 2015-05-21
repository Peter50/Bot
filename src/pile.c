#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

struct sElementPile{
	void * valeur;
	ElementPile suivant;
};

struct sPile{
	ElementPile tete;
	ElementPile queue;
};

ElementPile initElementPile(void * valeur){
	ElementPile element=malloc(sizeof(struct sElementPile));
	element->valeur=valeur;
	element->suivant=NULL;
	return element;
}

void detruireElementPile(ElementPile element){
	free(element);
}

Pile initPile(void){	
	Pile pile=malloc(sizeof(struct sPile));
	pile->tete=NULL;
	pile->queue=NULL;
	return pile;
}

void empiler(Pile pile,void * valeur){
	if(pile!=NULL){	
		ElementPile element=initElementPile(valeur);
		if(pile->tete==NULL){
			element->suivant=element;
			pile->tete=element;
			pile->queue=element;
		}
		else{
			element->suivant=pile->tete;
			pile->tete=element;
		}
	}
}

void * depiler(Pile pile){
	if(pile != NULL && pile->tete != NULL){
		void * valeur=pile->tete->valeur;
		ElementPile element=pile->tete;
		pile->tete=pile->tete->suivant;
		detruireElementPile(element);
		return valeur;
	}
	return NULL;
}
