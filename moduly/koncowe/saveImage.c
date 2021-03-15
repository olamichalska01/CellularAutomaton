#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

int multiplicity(int number, int difference)                                        
{                                                                                  
        int multiple = 0;                                                                              
        while(number > 1)                                                    
        {                                                                          
                multiple++;                                                     
                number -= difference;                                               
        }                                                                                          
        return multiple;                                                                
}          

void saveGeneration(generation *generationToSave)
{
	int		sizeOfSquare			= 	20;	
  	const int 	x_max 				= 	(generationToSave->c) * sizeOfSquare; 
  	const int 	y_max 				= 	(generationToSave->r) * sizeOfSquare;
  	const int 	MaxColorComponentValue 		= 	255;
  	char		*fileExtention			=	".pgm";
	char		*whatsInside			= 	"generation";
	char 		*numToString			=	(char*) malloc(sizeof(char));
	FILE 		*generatedImage;
//	char		*filename			=	"gen.pgm";
	unsigned char	data[y_max][x_max];

	sprintf(numToString, "%d", generationToSave -> Nr);
 
        char *filename = (char*)malloc(1 + strlen(fileExtention) + strlen(whatsInside) + strlen(numToString));
	strcpy(filename, whatsInside);
	strcat(filename, numToString);
	strcat(filename, fileExtention);

  	for (int y = 0; y < y_max; y += sizeOfSquare) 
  	{
		for (int x = 0; x < x_max; x += sizeOfSquare) 
		{
      			if( generationToSave -> gen[ multiplicity(y, sizeOfSquare) ][ multiplicity(x, sizeOfSquare) ] == 0 )
      			{
	      			for(int i = 0; i < sizeOfSquare; i++)
		      		{
		      			for(int j = 0; j < sizeOfSquare; j++)
					{
						data[y + i][x + j] = 220;
					}
		      		}
      			}
      			else 
	      		{
        			for(int i = 0; i < sizeOfSquare; i++)
        			{
              				for(int j = 0; j < sizeOfSquare; j++)
                			{
                        			data[y + i][x + j] = 55;
	                		}
        	      		}
      			}
    		}
  	}
 
	

	generatedImage = fopen(filename, "wb");
	fprintf(generatedImage, "P5\n %d\n %d\n %d\n", x_max, y_max, MaxColorComponentValue);
	fwrite(data, sizeof(data), 1, generatedImage);
	fclose(generatedImage);
	free(filename);
}
