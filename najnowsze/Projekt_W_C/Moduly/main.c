#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "manageGenerations.h"
#include "saveImage.h"
#include "modes.h"

int main(int argc, char** argv)
{
	int 		opt;
	int 		option_index 			= 	0;
	char*		input				=	NULL;
	char*		output				=	NULL;
	int 		number_of_generations 		= 	0;
	char* 		how_save			=	NULL;
	char 		to_save 			= 	'0';
	int 		how_many_to_save 		= 	0;
	char* 		which_mode			=	NULL;
	char*		how_check			= 	NULL;
	neighbour	how_check_neighbour 		= 	None;	
	int		how_many_parameters		=	0;
	int		length_of_word			=	0;

	static struct option long_options[] = 
	{
		{"in",  required_argument, NULL, 'i'},
		{"out", required_argument, NULL, 'o'},
		{"n",   required_argument, NULL, 'n'},
		{"s",   required_argument, NULL, 's'},
		{"m",   required_argument, NULL, 'm'},
		{"how", required_argument, NULL, 'h'},
		{NULL,  0,		   NULL,  0 }
	};

	while((opt = getopt_long(argc, argv, "i:o:n:s:m:h:", long_options, &option_index)) != -1)
	{
		switch(opt){

			case 'i': 
				input = optarg;
				break;

			case 'o':
				output = optarg;
				break;

			case 'n':
				number_of_generations = atoi(optarg);
				break;

			case 's': 
				how_save = optarg;		
				break;

			case 'm':
				which_mode = optarg;		
				break;

			case 'h':
				how_check = optarg;
				break;

			default:
				printf("\n\tParameterError\n\n");
				return 1;
		}

		how_many_parameters++;
	}
	
	if(how_many_parameters < 5 || how_many_parameters > 6)
	{
		printf("\n\tParameter Error\n\n");
		
		return 1;
	}

	if(how_many_parameters == 5 && how_save != NULL)
	{
		printf("\n\tParameter Error\n\n");

		return 1;
	}

	if(input == NULL || output == NULL || number_of_generations <= 0 || which_mode == NULL || how_check == NULL)
	{
		printf("\n\tParameter Error\n\n");

                return 1;
	}

	if(strcmp(how_check,"Mf") == 0)
	{
		how_check_neighbour = Mf;
	}
	else if(strcmp(how_check,"Ms") == 0)
        {
                how_check_neighbour = Ms;
        }
	else if(strcmp(how_check,"Ns") == 0)
        {
                how_check_neighbour = Ns;
        }
	else if(strcmp(how_check,"Nf") == 0)
        {
                how_check_neighbour = Nf;
        }
	else
	{
		printf("\n\tParameter Error\n\n");

                return 1;
	}

	if(strcmp(which_mode, "sbs") != 0 && strcmp(which_mode, "fast") != 0)
	{
	        printf("\n\tParameter Error\n\n");

                return 1;
	}	

	if(how_save != NULL && (how_save[0] == 'o' || how_save[0] == 'f'))
	{
		int 	i 	= 	1;
		
		to_save = how_save[0];
		
		while(how_save[i] != '\0')
		{
			if(how_save[i] >= '0' && how_save[i] <= '9')
			{
				how_many_to_save *= 10;
				how_many_to_save += how_save[i] - '0';
			}
			else 
			{
				printf("\n\tParameter Error\n\n");
		        
				return 1;
			}

			i++;
		}

	}
	else if(how_save != NULL)
	{
		printf("\n\tParameter Error\n\n");

                return 1;

	}

	length_of_word = strlen(input);

	if(length_of_word < 5 || !(input[length_of_word - 1] == 't' && input[length_of_word - 2] == 'x' && input[length_of_word - 3] == 't' && input[length_of_word - 4] == '.'))
	{
		printf("\n\tParameter Error\n\n");

                return 1;
	}	
	
	length_of_word = strlen(output);

        if(length_of_word < 5 || !(output[length_of_word - 1] == 't' && output[length_of_word - 2] == 'x' && output[length_of_word - 3] == 't' && output[length_of_word - 4] == '.'))
        {
                printf("\n\tParameter Error\n\n");

                return 1;
        }

	if(how_many_to_save > number_of_generations)
	{
		printf("\n\tParameter Error\n\n");

		return 1;
	}

	generation* first_generation = read_generation(input);
	
	if(strcmp(which_mode, "sbs") == 0)
	{
		first_generation = sbs(first_generation, number_of_generations, how_check_neighbour, to_save, how_many_to_save);
	}
	else
	{
		first_generation = fast(first_generation, number_of_generations, how_check_neighbour, to_save, how_many_to_save, number_of_generations, 0);
	}
	
	print_to_output(first_generation, output);

	free_generation(first_generation);

	return 0;
}
