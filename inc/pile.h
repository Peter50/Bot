#ifndef _PILE_
#define _PILE_

typedef struct sPile * Pile;

typedef struct sElementPile * ElementPile;

ElementPile initElementPile(void * valeur);

void detruireElementPile(ElementPile element);

Pile initPile(void);

void empiler(Pile pile,void * valeur);

void * depiler(Pile pile);


#endif
