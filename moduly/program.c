#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "neighbor.h"

extern int W;
extern int K;
extern int tab[23][35];
int neighbours[23][35] = {};

void poka();
void zamien();
void zapiszSasiadow(int world);
int isAlive(int w, int k);
int chooseWorld(int world, int w, int k);
void saveToTxtFile(FILE *file);



int main(int argc, char** argv)
{
	FILE *saveOutput = fopen(argv[1], "w");
	
	if(saveOutput == NULL) return -1;

	int howMany = argc > 2 ? atoi(argv[2]) : 10;
	int world = argc > 3 ? atoi(argv[3]) : 1;

	if(world > 4 || world < 1) return -1;

	while(howMany--)
	{
		poka();
		zapiszSasiadow(world);
		if(howMany == 0)
			saveToTxtFile(saveOutput);
		zamien();
	}

	fclose(saveOutput);


	return 0;
}

void saveToTxtFile(FILE *file)
{
	int i = 0;
	int j = 0;

	fprintf(file, "%d %d\n", W, K);

	for(i = 0; i < W; i++)
	{
		for(j = 0; j < K; j++)
		{
			fprintf(file, "%d ", tab[i][j]);
		}
	
		fprintf(file, "\n");
	}
}

void zapiszSasiadow(int world)
{
	int i = 0;
	int j = 0;

	for(i = 0; i < W; i++)
	{
		for(j = 0; j < K; j++)
		{
			neighbours[i][j] = chooseWorld(world ,i, j);
		}
	}

}

void zamien()
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < W; i++)
	{
		for(j = 0; j < K; j++)
		{
			if(isAlive(i, j) == 0 && neighbours[i][j] == 3)
				tab[i][j] = 1;
			else if(isAlive(i, j) == 1 && (neighbours[i][j] == 2 || neighbours[i][j] == 3))
				tab[i][j] = 1;
			else tab[i][j] = 0;
		}	
	}
}

void poka()
{
	system("clear");

	for(int i = 0; i < W; i ++)
        {
                for(int j = 0; j < K; j ++)
                {
                        if(tab[i][j] == 1)
                        {
                                printf("\u2b1c");
                        }

                        if(tab[i][j] == 0)
                        {
                                printf("\u2b1b");
                        }
                }
		
		printf("\n");
	}

	usleep(200000);
	
}

int isAlive(int w, int k)
{       
        return tab[w][k];
}       

int chooseWorld(int world, int w, int k)
{       
	int n = 0;
	
	switch(world)
	{
		case 1:
			n = MooreSphereWorld(w, k);
			break;
		case 2:
			n = MooreFlatWorld(w, k);
			break;
		case 3:
			n = NeumannSphereWorld(w, k);
			break;
		case 4:
			n = NeumannFlatWorld(w, k);
			break;
	}

        return n;
}
