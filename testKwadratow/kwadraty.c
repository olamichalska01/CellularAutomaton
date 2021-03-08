#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int W = 4;
int K = 4;
int tab[4][4] = { {1, 1, 1, 0} , {0, 1, 0, 1}, {0, 0, 0, 0}, {1, 0, 0, 1} };

void poka();
	
int main()
{

	poka();

	tab[1][2] = 1;
	tab[3][1] = 1;

	poka();

	

	return 0;
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
                                printf("\u25a0");
                                printf(" ");
                        }

                        if(tab[i][j] == 0)
                        {
                                printf("\u25a1");
                                printf(" ");
                        }
                }

                printf("\n");
        }

	sleep(1);
	
	
}

