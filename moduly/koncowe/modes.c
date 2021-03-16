#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "structures.h"
#include "saveImage.h"
#include "createNew.h"
#include "manageGenerations.h"

int theSame(generation *one, generation *two)
{
	if(one -> r != two -> r)
		return 0;
	if(one -> c != two -> c)
		return 0;
	for(int i = 0; i < (one -> r); i++)
	{
		for(int j = 0; j < (one -> c); j++)
		{
			if(one -> gen[i][j] != two -> gen[i][j])
				return 0;
		}
	}

	return 1;
}


void printGeneration(generation *ToPrint, char *mode, int howMany)
{
	system("clear");
	printf("\n\t\t\t\tGameOfLife\n\n");
	printf("\t\tMode in run: %s\n", mode);
	printf("\n\t\tGeneration number: %d of %d\n\n", ToPrint -> Nr, howMany);	
	
	for(int i = 0; i < ToPrint -> r; i ++)
	{
		
		printf("\t\t");
		
		for(int j = 0; j < ToPrint -> c; j++)
		{
			if((ToPrint -> gen[i][j]) == 0) 
				printf("\u2b1b");
			else 
				printf("\u2b1c");
		}
		
		printf("\n");
	}

}

void MakeNew(generation *IN, generation * FROM)
{
	IN -> r = FROM -> r;
	IN -> c = FROM -> c;
	IN -> Nr = FROM -> Nr;

	for(int i = 0; i < IN -> r; i++)
	{
		for(int j = 0; j < IN -> c; j++)
		{
			IN -> gen[i][j] = FROM -> gen[i][j];
		}
	}
}

generation *Fast(generation *first, int count, neighbour how, char toSave, int howManyToSave)
{
	generation *last = createGeneration(first -> r, first -> c);

	for(int i = 0; i < count; i++)
	{
		printGeneration(first, "FAST", count);

		if(toSave == 'o' && (first -> Nr) == howManyToSave)
		{
			saveGeneration(first);
		}
		else if(toSave == 'f' && (first -> Nr) <= howManyToSave)
		{
                        saveGeneration(first);
		}

		MakeNew(last,first);
		New(first, how); //brooo its fine, ive got this, just work pls

		if(theSame(last, first))
		{
			printf("\n\n\t\tNext generations look the same as  this one\n");
			break;
		}
		
		
		usleep(200000);	
	}
	printf("\n\n");

	freeGeneration(last);

	return first;
}

generation* SBS(generation *first, int count, neighbour how, char toSave, int howManyToSave)
{

	char question;
	generation *Each = createGeneration(first -> r, first -> c);
	
	for(int i = 0; i < count; i++)
	{
		printGeneration(first, "SBS", count);
		if(toSave == 'o' && (first -> Nr) == howManyToSave)
		{
			saveGeneration(first);
		}
		if(toSave == 'f' &&  (first -> Nr) <= howManyToSave)
		{
			saveGeneration(first);
		}

		if(i < count - 1)
		{
			printf("\n\n\t\t\tClick key: ");
			scanf("%c", &question);
		}
		else 
			printf("\n\n");

		if(question == 'e')
		{
			New(first, how);
			Fast( first, count - i - 1, how, toSave, howManyToSave );
			break;
		}
		else
		{
			MakeNew(Each, first);
			New(first, how);

			if(theSame(Each, first))
			{
				printf("\n\n\t\tNext generations look the same as this one\n");
				break;
			}
			
			

		}
	}

	freeGeneration(Each);
		
	return first;
}
