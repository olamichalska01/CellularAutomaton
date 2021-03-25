#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct gene
{
	int** gen;
	int r;
	int c;
	int nr;

}generation;

typedef enum 
{ 
	Mf = 1, Ms = 2, Ns = 3, Nf = 4, None = 0 

}neighbour;

#endif

