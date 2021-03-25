#ifndef MODES_H
#define MODES_H

int the_same(generation*, generation*);

void print_generation(generation*, char*);

void make_new(generation*, generation*);

generation* fast(generation*, int, neighbour, char, int, int, int);

generation* sbs(generation*, int, neighbour, char, int);

#endif
