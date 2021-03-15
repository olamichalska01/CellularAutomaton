#include <stdio.h>
#include "helpCreate.h"

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
	

	return;
}
