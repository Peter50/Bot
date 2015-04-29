#ifndef _ACCELERATION_
#define _ACCELERATION_

typedef struct sAcceleration * Acceleration;

Acceleration initAcceleration(int x, int y);

void detruireAcceleration(Acceleration acceleration);

#endif
