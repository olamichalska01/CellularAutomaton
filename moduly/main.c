#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"



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
				printf("\n\tParameterError 1 \n\n");
				return 1;
			
		}

		howManyParameters ++;
	}
	
	if(howManyParameters < 5 || howManyParameters > 6)
	{
		printf("\n\tParameter Error 2\n\n");
		
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




	printf("\tinput %s\n",input);
        printf("\toutput %s\n",output);
        printf("\tnumber %d\n",numberOfGenerations);
        printf("\twhichMode %s\n",whichMode);
        printf("\thow %s\n",howCheck);
        printf("\tsave %s\n",howSave);

	
	

		



	return 0;
}
