#ifndef MANAGEGENERATION_H
#define MANAGEGENERATION_H

#include "structures.h"

void freeGeneration(generation*);

generation * createGeneration(int , int);

void printToScreen(generation*);

void printToOutput(generation*, char *);

generation * readGeneration(char*);




#endif


