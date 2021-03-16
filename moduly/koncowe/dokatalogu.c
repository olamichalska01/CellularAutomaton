#include <stdio.h>



int main()
{
	FILE *in = fopen("./obrazy/jeej.txt", "w");

	fprintf(in, "jjej\n");

	fclose(in);

	return 0;
}
