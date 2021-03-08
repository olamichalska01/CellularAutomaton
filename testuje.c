#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int W = 17;
int K = 17;
int tab[17][17] = { {0}, 
		    {0}, 
		    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1}, 
		    {0}, 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0} , 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0} , 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0} , 
		    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1}, 
		    {0}, 
		    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1}, 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1} , 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1} , 
		    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1} , 
		    {0},
		    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1}, 
		    {0},
		    {0} };

int neighbours[17][17] = {};
void poka();
void zamien();
void zapiszSasiadow();
int isAlive(int w, int k);
int checkNeighbor(int w, int k);

int main(int argc, char** argv)
{
	int howMany = argc > 1 ? atoi(argv[1]) : 10;

	while(howMany--)
	{
		poka();
		zapiszSasiadow();
		zamien();
	}

	return 0;
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

	usleep(300000);
	
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
