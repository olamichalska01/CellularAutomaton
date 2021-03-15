#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *cz1 = "gen";
	long int cz2int = 1111111111111111113;
	char *cz2char = (char*)malloc(sizeof(char) * 1);

	sprintf(cz2char, "%ld", cz2int);

	printf("%s\n", cz2char);
	return 0;
}
