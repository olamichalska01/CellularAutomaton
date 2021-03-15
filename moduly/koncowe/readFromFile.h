#ifndef READFROMFILE_H
#define READFROMFILE_H

void readFromFile(generation *g, char *fname);
void printFileData(generation *g, char *fname);
void createFirstGeneration(generation *g, int rows, int columns);
void freeArray(generation *g);

#endif
