#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "file.h"

struct sFile{

	Element tete;
	Element queue;
};

struct sElement{

	void * valeur;
	Element suivant;
};

Element initElement(void * valeur){

	Element element=malloc(sizeof(struct sElement));
	element->valeur=valeur;
	element->suivant=NULL;

	return element;
}

void detruireElement(Element element){
	if(element!=NULL){
		free(element);
	}
}

File initFile(void){

	File file=malloc(sizeof(struct sFile));
	file->tete=NULL;
	file->queue=NULL;	

	return file;
}

void detruireFile(File file){

	while(!(fileEstVide(file))){
		defiler(file);
	}
	if(file!=NULL){
		free(file);
	}
}

int fileEstVide(File file){
	if(file == NULL || file->tete==NULL){
		return 1;
	}
	return 0;
}

void enfiler(File file, void * valeur){

	assert(file!=NULL);

	Element element=initElement(valeur);

	if(!(fileEstVide(file))){
		file->queue->suivant=element;
		file->queue=element;
		element->suivant=NULL;
	}
	else{
		file->tete=element;
		file->queue=element;
	}
}

void * defiler(File file){

	assert(!(fileEstVide(file)));

	void * valeur=file->tete->valeur;

	if(file->tete->suivant!=file->tete){
		Element element=file->tete;
		file->tete=file->tete->suivant;
		file->tete->suivant=NULL;
		detruireElement(element);
	}
	else{
		detruireElement(file->queue);
		file->tete=NULL;
		file->queue=NULL;
	}
	return valeur;
}

void concatFile(File file1, File file2){

	assert(!(fileEstVide(file1)) && !(fileEstVide(file2)));

	file1->queue->suivant=file2->tete;
	file1->queue=file2->queue;
	free(file2);
}

void afficherFile(File file, void (*fonction)(void *)){

	assert(!(fileEstVide(file)));

	Element element=file->tete;
	do{
		fonction(element->valeur);
		element=element->suivant;
	}while(element!=NULL);
}

void afficherInt(void * integer){
	printf("%d\n",*(int *)integer);
}

File copieFile(File file){

	assert(!(fileEstVide(file)));

	File file2=initFile();
	if(!(fileEstVide(file))){
		Element element=file->tete;
		do{
			enfiler(file2,element->valeur);
			element=element->suivant;
		}while(element!=NULL);
	}

	return file2;
}
