#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "structures.h"

int MooreSphereWorld(generation *worldGeneration, int row, int column);

int MooreFlatWorld(generation *worldGeneration, int row, int column);

int NeumannSphereWorld(generation *worldGeneration, int row, int column);

int NeumannFlatWorld(generation *worldGeneration, int row, int column);

#endif

