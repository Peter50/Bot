#ifndef _POSITION_
#define _POSITION_

typedef struct sPosition * Position;

Position initPosition(int x, int y);

void detruirePosition(Position position);

#endif
