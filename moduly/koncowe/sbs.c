

int theSame(generation *one, generation *two)
{
	if(one -> r != two -> r)
		return 0;
	if(one -> c != two -> c)
		return 0;
	for(int i = 0; i < (one -> r); i++)
	{
		for(int j = 0; j < (one -> c); j++)
		{
			if(one -> gen[i][j] != two -> gen[i][j])
				return 0;
		}
	}

	retrun 1;
}

void printGeneration(generation *ToPrint, char *mode)
{
	system("clear");
	printf("\n\t\tGameOfLife\n");
	printf("\t\tMode in run: %s\n", mode);
	printf("\n\t\tNumber of generation: %d\n", ToPrint -> Nr);
	
	
	for(int i = 0; i < ToPrint -> r; i ++)
	{
		
		printf("\t\t\t");
		
		for(int j = 0; j < ToPrint -> c; j++)
		{
			if((ToPrint -> gen[i][j]) == 0) 
				printf("\u2b1c");
			else 
				printf("\u2b1b");
		}
		
		printf("\n");
	}

}

generation* SBS(generation *first, int count, neighbour how, char toSave, int howManyToSave)
{

	char question;
	generation *Each;
	
	for(int i = 0; i < count; i++)
	{
		printGeneration(first, "SBS");
		if(toSave == 'o' && i == howManyToSave - 1)
		{
			saveGeneration(first);
		}
		if(toSave == 'f' &&  i < howManyToSave)
		{
			saveGeneration(first);
		}

		scanf("%c", &question);

		if(question == 'e')
		{
			FAST();
		}
		else
		{
			each = New(first, how);
			if(theSame(Each, first))
			{
				printf("\n\t\tNext generations look the same as this one\n");
				break;
			}
			first = Each;

			freeGeneration(Each);


		}


	}




}
