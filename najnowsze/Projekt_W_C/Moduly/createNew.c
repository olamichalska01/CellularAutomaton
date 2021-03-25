#include <stdio.h>

#include "helpCreate.h"
#include "manageGenerations.h"
#include "structures.h"

int rules(int how_many_neighbours, int is_alive)
{
	if(is_alive == 0 && how_many_neighbours == 3)
	{
		return 1;		
	}
	else if(is_alive == 1 && (how_many_neighbours != 2 && how_many_neighbours != 3))
	{
		return 0;
	}
	else 
	{
		return is_alive;
	}
}

int population(generation* current_generation)
{
	int 	rows 			= 	current_generation -> r;
	int 	columns 		= 	current_generation -> c;
	int 	population_number 	= 	0;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(current_generation -> gen[i][j] == 1)
			{
				population_number += 1;
			}
		}
	}

	return population_number;
}

void new_gen(generation* old_generation, neighbour how)
{
	int** 	neighbourhood 		= 	create_neighbourhood(old_generation, how);
	
	old_generation -> nr = (old_generation -> nr) + 1;

	for(int i = 0; i < old_generation -> r; i++)
	{
		for(int j = 0; j < old_generation -> c; j++)
		{
			old_generation -> gen[i][j] = rules(neighbourhood[i][j], old_generation -> gen[i][j]);
		}
	}

	free_neighbourhood(old_generation, neighbourhood);	
}
