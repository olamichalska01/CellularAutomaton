#include <stdio.h>
#include "structures.h"
#include "createNew.h"
#include "manageGenerations.h"

int main()
{
	generation *A = readGeneration("plik.txt");
	neighbour B = Ms;

	printToScreen(A);

	New(A, B);		
	
	printToScreen(A);		

	freeGeneration(A);

	return 0;
}
