#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "structures.h"
#include "saveImage.h"
#include "createNew.h"
/*
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
*/

void printGeneration(generation *ToPrint, char *mode)
{
	system("clear");
	printf("\n\t\tGameOfLife\n");
	printf("\t\tMode in run: %s\n", mode);
	printf("\n\t\tNumber of generation: %d\n\n", ToPrint -> Nr);	
	
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

generation *Fast(generation *first, int count, neighbour how, char toSave, int howManyToSave)
{
	//generation *last;

	for(int i = 0; i < count; i++)
	{
		printGeneration(first, "FAST");

		if(toSave == 'o' && (first -> Nr) == howManyToSave)
		{
			saveGeneration(first);
		}
		else if(toSave == 'f' && (first -> Nr) <= howManyToSave)
		{
                        saveGeneration(first);
		}

		New(first, how); //brooo its fine, ive got this, just work pls

		/*if(theSame(last, first))
		{
			printf("\n\nNext generations look the same as  this one\n");
			break;
		}
		*/
		//first = last;
		//freeGeneration(last);
		
		usleep(300000);	
	}
	printf("\n\n");

	return first;
}

generation* SBS(generation *first, int count, neighbour how, char toSave, int howManyToSave)
{

	char question;
//	generation *Each;
	
	for(int i = 0; i < count; i++)
	{
		printGeneration(first, "SBS");
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
			New(first, how);
//			Each = New(first, how);
			/*if(theSame(Each, first))
			{
				printf("\n\t\tNext generations look the same as this one\n");
				break;
			}
			*/
//			first = Each;

//			freeGeneration(Each);
		}
	}
	
	return first;
}
