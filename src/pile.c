#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

struct sElementPile{
	void * valeur;
	ElementPile suivant;
	ElementPile precedent;
}

struct sPile{
	ElementPile tete;
	ElementPile queue;
}

ElementPile initElementPile(void * valeur){
	ElementPile element=malloc(sizeof(struct sElementPile));
	element->valeur=valeur;
	element->suivant=NULL;
	element->precedent=NULL;
	return element;
}

Pile initPile(void){	
	Pile pile=malloc(sizeof(struct sPile));
	pile->tete=NULL;
	pile->queue=NULL;
	return pile;
}

void enpiler(Pile pile,void * valeur){
	if(pile!=NULL){	
		ElementPile element=initElementPile(valeur);
		if(pile->tete==NULL){
			element->suivant=element;
			element->precedent=element;
			pile->tete=element;
			pile->queue=element;
		}
		else{
			file->queue->suivant=element;
			element->precedent=file->queue;
			file->queue=element;
			element->suivant=NULL;
		}
	}
}

void * depiler(Pile pile){

}
