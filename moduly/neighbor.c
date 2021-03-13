#include "neighbor.h"

int W = 7;
int K = 35;
int tab[23][35] = { 
		    {0},
       		    {0},	
		    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
		    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                  }; 



int MooreSphereWorld(int w, int k)
{       
        int neighbours = 0;

        neighbours += tab[(w + W - 1) % W][k];                   // N
        neighbours += tab[(w + W + 1) % W][k];                   // S
        neighbours += tab[w][(k + K - 1) % K];                   // W
        neighbours += tab[w][(k + K + 1) % K];                   // W
        neighbours += tab[(w + W - 1) % W][(k + K + 1) % K];     // NE
        neighbours += tab[(w + W - 1) % W][(k + K - 1) % K];     // NW
        neighbours += tab[(w + W + 1) % W][(k + K + 1) % K];     // SE
        neighbours += tab[(w + W + 1) % W][(k + K - 1) % K];     // SW

        return neighbours;

}       

int MooreFlatWorld(int w, int k)
{
	int neighbours = 0;
        	
	if(w != 0)	
		neighbours += tab[w - 1][k];         // N
	if(w != W - 1)        
		neighbours += tab[w + 1][k];         // S
       	if(k != 0)	
		neighbours += tab[w][k - 1];         // W
        if(k != K - 1) 	
		neighbours += tab[w][k + 1];         // E
	if(w != 0 && k != K - 1)        
		neighbours += tab[w - 1][k + 1];     // NE
        if(w != 0 && k != 0)	
		neighbours += tab[w - 1][k - 1];     // NW
	if(w != W - 1 && k != K - 1)        
		neighbours += tab[w + 1][k + 1];     // SE
        if(w != W - 1 && k != 0)
		neighbours += tab[w + 1][k - 1];     // SW
	
	return neighbours;
}

int NeumannSphereWorld(int w, int k)
{
        int neighbours = 0;

	neighbours += tab[(w + W - 1) % W][k];                   // N
        neighbours += tab[(w + W + 1) % W][k];                   // S
        neighbours += tab[w][(k + K - 1) % K];                   // W
        neighbours += tab[w][(k + K + 1) % K];                   // E

        return neighbours;
}

int NeumannFlatWorld(int w, int k)
{
        int neighbours = 0;

	if(w != 0)
                neighbours += tab[w - 1][k];         // N
        if(w != W - 1)
                neighbours += tab[w + 1][k];         // S
        if(k != 0)
                neighbours += tab[w][k - 1];         // W
        if(k != K - 1)
                neighbours += tab[w][k + 1];         // E

        return neighbours;
}
