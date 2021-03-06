#include <stdio.h>

int W = 4;
int K = 4;
int tab[4][4] = {{0,1,1,0}, {0,0,0,1}, {1,1,0,1}, {0,1,0,1}};


int isAlive(int w, int k);
int checkNeighbor(int w, int k);

int main()
{       

        printf("Komorka [0][1] jest %s, ma %d sasiadow\n",isAlive(0,1) == 1? "zywa" : "martwa", checkNeighbor(0,1));




        return 0;
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

