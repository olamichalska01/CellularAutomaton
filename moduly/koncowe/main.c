#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "manageGenerations.h"
#include "saveImage.h"


int main( int argc, char** argv)
{
	int 		opt;
	int 		option_index 			= 	0;
	FILE 		*filein 			=	NULL;
	char*		input				=	NULL;
	FILE 		*fileout 			= 	NULL;
	char*		output				=	NULL;
	int 		numberOfGenerations 		= 	0;
	char* 		howSave				=	NULL;
	char 		toSave 				= 	'0';
	int 		howManyToSave 			= 	0;
	char* 		whichMode			=	NULL;
	char*		howCheck			= 	NULL;
	neighbour	howCheckNeighbour 		= 	None;	
	int		howManyParameters		=	0;
	int		lengthOfWord			=	0;
	


	static struct option long_options[] = {
	{"in",  required_argument, NULL, 'i'},
	{"out", required_argument, NULL, 'o'},
	{"n",   required_argument, NULL, 'n'},
	{"s",   required_argument, NULL, 's'},
	{"m",   required_argument, NULL, 'm'},
	{"how", required_argument, NULL, 'h'},
	{NULL,     0,              NULL,  0 }
	};

	while((opt = getopt_long( argc, argv, "i:o:n:s:m:h:", long_options, &option_index)) != -1)
	{
		switch(opt){

			case 'i': 
				input = optarg;
				break;

			case 'o':
				output = optarg;
				break;

			case 'n':
				numberOfGenerations = atoi(optarg);
				break;

			case 's': 
				howSave = optarg;		
				break;

			case 'm':
				whichMode = optarg;		
				break;

			case 'h':
				howCheck = optarg;
				break;

			default:
				printf("\n\tParameterError 1\n\n");
				return 1;
			
		}

		howManyParameters ++;
	}
	
	if(howManyParameters < 5 || howManyParameters > 6)
	{
		printf("\n\tParameter Error 2 %d\n\n", howManyParameters);
		
		return 1;
	}

	if(howManyParameters == 5 && howSave != NULL)
	{
		printf("\n\tParameter Error 3\n\n");

		return 1;
	}

	if(input == NULL || output == NULL || numberOfGenerations <= 0 || whichMode == NULL || howCheck == NULL)
	{
		printf("\n\tParameter Error 4\n\n");

                return 1;
	}

	if(strcmp(howCheck,"Mf") == 0 )
	{
		howCheckNeighbour = Mf;
	}
	else if(strcmp(howCheck,"Ms") == 0 )
        {
                howCheckNeighbour = Ms;
        }
	else if(strcmp(howCheck,"Ns") == 0 )
        {
                howCheckNeighbour = Ns;
        }
	else if(strcmp(howCheck,"Nf") == 0 )
        {
                howCheckNeighbour = Nf;
        }
	else
	{
		printf("\n\tParameter Error 5\n\n");

                return 1;
	}

	if(strcmp(whichMode, "sbs") != 0 && strcmp(whichMode, "fast") != 0 )
	{
	        printf("\n\tParameter Error 6\n\n");

                return 1;

	}	

	if(howSave[0] == 'o' || howSave[0] == 'f')
	{
		int i = 1;
		
		toSave = howSave[0];
		
		if(howSave[1] == '0')
		{
			printf("\n\tParameter Error 7\n\n");

                        return 1;
		}

		while(howSave[i] != '\0')
		{

			if(howSave[i] >= '0' && howSave[i] <= '9')
			{
				howManyToSave *= 10;
				howManyToSave += howSave[i] - '0';
			}
			else 
			{
				printf("\n\tParameter Error 7\n\n");
		                return 1;
			}

			i ++;
		}

	}
	else
	{
		printf("\n\tParameter Error 7\n\n");

                return 1;

	}

	lengthOfWord = strlen(input);

	if(lengthOfWord < 5 || !(input[lengthOfWord - 1] == 't' && input[lengthOfWord - 2] == 'x' && input[lengthOfWord - 3] == 't' 			&& input[lengthOfWord - 4] == '.'))
	{
		printf("\n\tParameter Error 8\n\n");

                return 1;

	}	
	
	lengthOfWord = strlen(output);

        if(lengthOfWord < 5 || !(output[lengthOfWord - 1] == 't' && output[lengthOfWord - 2] == 'x' && output[lengthOfWord - 3] == 't'                     && output[lengthOfWord - 4] == '.'))
        {
                printf("\n\tParameter Error 9\n\n");

                return 1;

        }



	printf("\tinput %s\n",input);
        printf("\toutput %s\n",output);
        printf("\tnumber %d\n",numberOfGenerations);
        printf("\twhichMode %s\n",whichMode);
        printf("\thow %s\n",howCheck);
        printf("\tsave %s\n",howSave);
	printf("\tnrSave %d\n", howManyToSave);
	printf("\tcharSave %c\n", toSave);

	generation *A = readGeneration(input);

	printf("222\n");
	printToScreen(A);
	
	printToOutput(A, output);

	freeGeneration(A);
	


	return 0;
}
