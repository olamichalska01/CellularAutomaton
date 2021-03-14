#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


void createFirstGeneration(generation *g, int rows, int columns)
{
        g = (generation*)malloc(sizeof(generation));

        if(g != NULL)
        {
                //g->r = (int)malloc(sizeof(int));
                g->r = rows;
		//g->c = (int)malloc(sizeof(int));
		g->c = columns;
		//g->Nr = (int)malloc(sizeof(int));
                g->gen = (int**)malloc(sizeof(int*) * rows);

                for(int i = 0; i < rows; i++)
                {
                        g->gen[i] = (int*)malloc(sizeof(int*) * columns);
                }
        }
}

void readFromFile(generation *g, char *fname)
{
	int r;
	int c;

	FILE *inputData = fopen(fname, "r");

	if(inputData != NULL)
	{
		fscanf(inputData, "%d %d", &r, &c);
		createFirstGeneration(g, r, c);

		if(g != NULL)
		{
			for(int rIndex = 0; rIndex < r; rIndex++)
				for(int cIndex = 0; cIndex < c; cIndex++)
					fscanf(inputData, "%d", &(g->gen[rIndex][cIndex]));
		}
		else 
		{
			fprintf(stderr, "FileError %s (gen error)", fname);		
		}

		fclose(inputData);
	}
	else 
	{
		fprintf(stderr, "FileError %s (unable to open file)", fname);
	}
}

void printFileData(generation *g, char *fname)
{
	FILE *out = fopen(fname, "w");

	fprintf(out, "%d %d\n", g->r, g->c);
	
	for(int i = 0; i < g->r; i++)
	{
		for(int j = 0; j < g->c; j++)
			fprintf(out, "%d ", g->gen[i][j]);

		fprintf(out, "\n");
	}
}


void freeArray(generation *g)
{
	for(int i = 0; i < g->r; i++)
		free(g->gen[i]);	
	free(g->gen);
	free(g);	
}

