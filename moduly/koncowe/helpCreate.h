#ifndef HELPCREATE_H
#define HELPCREATE_H
#include "structures.h"

int **createNeighbourhood(generation *whichGeneration, neighbour how);

void freeNeighbourhood(generation *whichGeneration, int **neighbourhood);

#endif
