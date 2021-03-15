#include "neighbor.h"
#include "structures.h"


int MooreSphereWorld(generation *worldGeneration, int row, int column)
{       
        int neighbours = 0;

        neighbours += worldGeneration -> gen[(row + worldGeneration -> r - 1) % worldGeneration -> r][column];                  
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r + 1) % worldGeneration -> r][column];                 
        neighbours += worldGeneration -> gen[row][(column + worldGeneration -> c - 1) % worldGeneration -> c];                
        neighbours += worldGeneration -> gen[row][(column + worldGeneration -> c + 1) % worldGeneration -> c];               
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r - 1) % worldGeneration -> r][(column + worldGeneration -> c + 1) % worldGeneration -> c];
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r - 1) % worldGeneration -> r][(column + worldGeneration -> c - 1) % worldGeneration -> c];
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r + 1) % worldGeneration -> r][(column + worldGeneration -> c + 1) % worldGeneration -> c];
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r + 1) % worldGeneration -> r][(column + worldGeneration -> c - 1) % worldGeneration -> c];

        return neighbours;

}       

int MooreFlatWorld(generation *worldGeneration, int row, int column)
{
	int neighbours = 0;
        	
	if(row != 0)	
		neighbours += worldGeneration -> gen[row - 1][column];         
	if(row != worldGeneration -> r - 1)        
		neighbours += worldGeneration -> gen[row + 1][column];         
       	if(column != 0)	
		neighbours += worldGeneration -> gen[row][column - 1];         
        if(column != worldGeneration -> c - 1) 	
		neighbours += worldGeneration -> gen[row][column + 1];         
	if(row != 0 && column != worldGeneration -> c - 1)        
		neighbours += worldGeneration -> gen[row - 1][column + 1];     
        if(row != 0 && column != 0)	
		neighbours += worldGeneration -> gen[row - 1][column - 1];     
	if(row != worldGeneration -> r - 1 && column != worldGeneration -> c - 1)        
		neighbours += worldGeneration -> gen[row + 1][column + 1];     
        if(row != worldGeneration -> r - 1 && column != 0)
		neighbours += worldGeneration -> gen[row + 1][column - 1];     
	
	return neighbours;
}

int NeumannSphereWorld(generation *worldGeneration, int row, int column)
{
        int neighbours = 0;

	neighbours += worldGeneration -> gen[(row + worldGeneration -> r - 1) % worldGeneration -> r][column];       
        neighbours += worldGeneration -> gen[(row + worldGeneration -> r + 1) % worldGeneration -> r][column];       
        neighbours += worldGeneration -> gen[row][(column + worldGeneration -> c - 1) % worldGeneration -> c];       
        neighbours += worldGeneration -> gen[row][(column + worldGeneration -> c + 1) % worldGeneration -> c];       

        return neighbours;
}

int NeumannFlatWorld(generation *worldGeneration, int row, int column)
{
        int neighbours = 0;

	if(row != 0)
                neighbours += worldGeneration -> gen[row - 1][column];         
        if(row != worldGeneration -> r - 1)
                neighbours += worldGeneration -> gen[row + 1][column]; 
        if(column != 0)
                neighbours += worldGeneration -> gen[row][column - 1]; 
        if(column != worldGeneration -> c - 1)
                neighbours += worldGeneration -> gen[row][column + 1]; 

        return neighbours;
}
