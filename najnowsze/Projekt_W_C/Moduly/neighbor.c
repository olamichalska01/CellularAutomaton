#include "neighbor.h"

int moore_sphere_world(generation* world_generation, int row, int column)
{       
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r	 	= 	world_generation -> r;

        neighbours += world_generation -> gen[(row + r - 1) % r][column];                  
        neighbours += world_generation -> gen[(row + r + 1) % r][column];                 
        neighbours += world_generation -> gen[row][(column + c - 1) % c];                
        neighbours += world_generation -> gen[row][(column + c + 1) % c];               
        neighbours += world_generation -> gen[(row + r - 1) % r][(column + c + 1) % c];
        neighbours += world_generation -> gen[(row + r - 1) % r][(column + c - 1) % c];
        neighbours += world_generation -> gen[(row + r + 1) % r][(column + c + 1) % c];
        neighbours += world_generation -> gen[(row + r + 1) % r][(column + c - 1) % c];

        return neighbours;

}       

int moore_flat_world(generation* world_generation, int row, int column)
{
	int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
        	
	if(row != 0)	
	{
		neighbours += world_generation -> gen[row - 1][column];         
	}
	
	if(row != r - 1)        
	{
		neighbours += world_generation -> gen[row + 1][column];         
	}
	
	if(column != 0)	
	{
		neighbours += world_generation -> gen[row][column - 1];         
	}
	
	if(column != c - 1) 	
	{
		neighbours += world_generation -> gen[row][column + 1];         
	}
	
	if(row != 0 && column != c - 1)        
	{
		neighbours += world_generation -> gen[row - 1][column + 1];     
	}
	
	if(row != 0 && column != 0)	
	{
		neighbours += world_generation -> gen[row - 1][column - 1];     
	}	
	
	if(row != r - 1 && column != c - 1)        
	{
		neighbours += world_generation -> gen[row + 1][column + 1];     
	}
	
	if(row != r - 1 && column != 0)
	{
		neighbours += world_generation -> gen[row + 1][column - 1];     
	}

	return neighbours;
}

int neumann_sphere_world(generation* world_generation, int row, int column)
{
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
	
	neighbours += world_generation -> gen[(row + r - 1) % r][column];       
        neighbours += world_generation -> gen[(row + r + 1) % r][column];       
        neighbours += world_generation -> gen[row][(column + c - 1) % c];       
        neighbours += world_generation -> gen[row][(column + c + 1) % c];       

        return neighbours;
}

int neumann_flat_world(generation* world_generation, int row, int column)
{
        int 	neighbours 	= 	0;
	int 	c 		= 	world_generation -> c;
	int 	r 		= 	world_generation -> r;
	
	if(row != 0)
	{
                neighbours += world_generation -> gen[row - 1][column];         
	}
	
	if(row != r - 1)
	{
		neighbours += world_generation -> gen[row + 1][column]; 
	}
	
	if(column != 0)
	{
		neighbours += world_generation -> gen[row][column - 1]; 
	}
	
	if(column != c - 1)
	{
 		neighbours += world_generation -> gen[row][column + 1]; 
	}

        return neighbours;
}
