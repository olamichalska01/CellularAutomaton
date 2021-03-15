#include <stdio.h>
#include "helpCreate.h"
#include "manageGenerations.h"

int Rules(int howManyNeighbours, int isAlive)
{
	if(isAlive == 0 && (howManyNeighbours == 2 || howManyNeighbours == 3))
	{
		return 1;		
	}
	else if(isAlive == 1 && (howManyNeighbours != 2 && howManyNeighbours != 3))
	{
		return 0;
	}
	else return isAlive;

}

generation *New(generation *oldGeneration, neighbour how)
{
	generation *newGeneration =  createGeneration(oldGeneration -> r, oldGeneration -> c);

	newGeneration -> Nr = (oldGeneration -> Nr) + 1;

	int **neighbourhood = createNeighbourhood(oldGeneration, how);

	for(int i = 0; i < oldGeneration -> r; i++)
	{
		for(int j = 0; j < oldGeneration -> c; j++)
		{
			newGeneration -> gen[i][j] = Rules(neighbourhood[i][j], oldGeneration -> gen[i][j]);
		}
	}

	freeNeighbourhood();	

	return newGeneration;
}
