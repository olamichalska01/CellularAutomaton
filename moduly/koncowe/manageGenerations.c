#include <stdio.h>
#include <stdlib.h>

#include "structures.h"



void freeGeneration(generation* GenToClear)
{
	for(int i = 0; i < GenToClear -> r; i++)
	{
		free(GenToClear -> gen[i]);
	}

	free(GenToClear -> gen);
	free(GenToClear);
}

generation * createGeneration(int row, int column)
{
	generation * NewGen = (generation*) malloc(sizeof(generation));

	if(NewGen != NULL)
	{
		NewGen -> r = row;
		NewGen -> c = column;
		NewGen -> Nr = 1;
		NewGen -> gen = (int **) malloc(sizeof(int*) * row);

		for(int i = 0; i < row; i++)
		{
			NewGen -> gen[i] = (int*) malloc(sizeof(double) * column);
		}
	}

	return NewGen;
}

void printToScreen(generation* GenToPrint)
{
	printf("%d %d\n", GenToPrint -> r, GenToPrint -> c);

	for(int i = 0; i < GenToPrint -> r; i++)
	{

		for(int j = 0; j < GenToPrint -> c; j++)
		{
			printf("%d ", GenToPrint -> gen[i][j]);
		}
		printf("\n");
	}
}

void printToOutput(generation* GenToPrint, char * fileName)
{
	FILE *file = fopen(fileName, "w");

	
	fprintf(file, "%d %d\n", GenToPrint -> r, GenToPrint -> c);

	for(int i = 0; i < GenToPrint -> r; i++)
       	{
 
                for(int j = 0; j < GenToPrint -> c; j++)
                {	
                        fprintf(file, "%d ", GenToPrint -> gen[i][j]);
                }
                fprintf(file, "\n");
        	
	}

	fclose(file);

}

generation * readGeneration(char* fileName)
{
	int row, column;
	FILE *file = fopen(fileName, "r");
	generation *GenToRead = NULL;

	if(file != NULL)
	{
		if(fscanf(file, "%d %d", &row, &column) != 2)
		{
			printf("Blad przy odczytaniu kolumn i wierszy\n");
			return NULL;
		}

		GenToRead = createGeneration(row, column);

		if(GenToRead != NULL)
		{
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < column; j++)
				{
					if(fscanf(file,"%d",&(GenToRead -> gen[i][j])) != 1)
					{
						printf("blad przy odczycie danej \n");
						return NULL;
					}
					if(GenToRead -> gen[i][j] != 0 && GenToRead -> gen[i][j] != 1)
					{
						printf("blad wartosci danej\n");
						return NULL;
					}
				}
			}
		}
		else
		{
			printf("blad przy tworzeniu macierzy\n");
			return NULL;
		}

		
	}
	else
	{
		printf("blad przy odczycie pliku\n");
		return NULL;
	}

	return GenToRead;

}



