#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "neighbor.h"

int **createNeighbourhood(generation *whichGeneration, neighbour how)
{
	int rows = whichGeneration -> r;
	int columns = whichGeneration -> c;

	int **neighbourhood = (int**)malloc(sizeof(int*) * rows);

	for(int i = 0; i < rows; i++)
		neighbourhood[i] = (int*)malloc(sizeof(int) * columns);
	
	if(how == Ms)
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0 ; j < columns; j++)
			{
				neighbourhood[i][j] = MooreSphereWorld(whichGeneration, i, j); 
			}
		}
	}
	else if(how == Mf)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = MooreFlatWorld(whichGeneration, i, j);
                        }
                }
	}
	else if(how == Ns)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = NeumannSphereWorld(whichGeneration, i, j);
                        }
                }
	}
	else if(how == Nf)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = NeumannFlatWorld(whichGeneration, i, j);
                        }
                }
	}

	return neighbourhood;
}

void freeNeighbourhood(generation *whichGeneration, int **neighbourhood)
{
	int rows = whichGeneration -> r;

	for(int i = 0; i < rows; i++)
                free(neighbourhood[i]);

	free(neighbourhood);
}
