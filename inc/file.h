#ifndef _FILE_
#define _FILE_

typedef struct sElement * Element;

typedef struct sFile * File;

Element initElement(void * valeur);

void detruireElement(Element element);

File initFile(void);

void detruireFile(File file);

int fileEstVide(File file);

void enfiler(File file,void * valeur);

void * defiler(File file);

void concatFile(File file1, File file2);

void afficherFile(File file,void (*fonction)(void *));

void afficherInt(void * integer);

File copieFile(File file);

#endif 
