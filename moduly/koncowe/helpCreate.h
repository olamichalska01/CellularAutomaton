#ifndef HELPCREATE_H
#define HELPCREATE_H

int **createNeighbourhood(generation *whichGeneration, neighbour how);

void freeNeighbourhood(generation *whichGeneration, int **neighbourhood);

#endif
