#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int W = 4;
int K = 4;
int tab[4][4] = { {0, 0, 1, 0}, 
		  {0, 1, 0, 1}, 
	   	  {1, 0, 0, 0}, 
		  {0, 1, 1, 0} }; 

int neighbours[4][4] = {};
void poka();
void zamien();
void zapiszSasiadow();
int isAlive(int w, int k);
int checkNeighbor(int w, int k);
void saveToFile(FILE *file);


int main(int argc, char** argv)
{
	FILE *saveOutput = fopen(argv[1], "w");
	
	if(saveOutput == NULL) return -1;

	int howMany = argc > 2 ? atoi(argv[2]) : 10;

	while(howMany--)
	{
		poka();
		zapiszSasiadow();
		zamien();
	}

	saveToFile(saveOutput);
	fclose(saveOutput);


	return 0;
}

void saveToFile(FILE *file)
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

void zapiszSasiadow()
{
	int i = 0;
	int j = 0;

	for(i = 0; i < W; i++)
	{
		for(j = 0; j < K; j++)
		{
			neighbours[i][j] = checkNeighbor(i, j);
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

	sleep(1);
	
}

int isAlive(int w, int k)
{       
        return tab[w][k];
}       

int checkNeighbor(int w, int k)
{       
        int s = 0;

        s += tab[(w + W - 1) % W][k];                   // W
        s += tab[(w + W + 1) % W][k];                   // E
        s += tab[w][(k + K - 1) % K];                   // S
        s += tab[w][(k + K + 1) % K];                   // N
        s += tab[(w + W - 1) % W][(k + K + 1) % K];     // NW
        s += tab[(w + W - 1) % W][(k + K - 1) % K];     // WS
        s += tab[(w + W + 1) % W][(k + K + 1) % K];     // NE
        s += tab[(w + W + 1) % W][(k + K - 1) % K];     // ES

        return s;

}       
