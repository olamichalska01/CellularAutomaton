#ifndef MODES_H
#define MODES_H

int theSame(generation *one, generation *two);

void printGeneration(generation *ToPrint, char *mode);

generation *Fast(generation *first, int count, neighbour how, char toSave, int howManyToSave);

generation* SBS(generation *first, int count, neighbour how, char toSave, int howManyToSave);

#endif
