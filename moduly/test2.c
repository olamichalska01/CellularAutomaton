#include <stdio.h>
/*(y % (2*s) == 0 && x % (2*s) == 0) || (y % (2*s) == s && x % (2*s) == s)*/

int s = 20;
int W = 23;
int K = 35;
int tab[23][35] = { {0},
                    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1},
                    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1},
                    {0},
                    {0, 0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1, 1},
                    {0},
                    {0},
                    {0},
                    {0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                    {0},
                    {0},
                    {0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0}  };


int ile(int y, int s);

int main()
{
  
  	const char *filename = "n.pgm";
  	int x, y;
 	
	/* size of the image */
  	const int x_max = K*s;  /* width */
  	const int y_max = W*s;  /* height */
  	
	/* 2D array for colors (shades of gray) */
  	unsigned char data[y_max][x_max];
  	
	/* color component is coded from 0 to 255 ;  it is 8 bit color file */
  	const int MaxColorComponentValue = 255;
  	FILE * fp;
  	
	/* comment should start with # */
  	//const char *comment = "# this is my new binary pgm file";
 
  	for (y = 0; y < y_max; y += s) 
  	{
		for (x = 0; x < x_max; x += s) 
		{
      			if(tab[ile(y,s)][ile(x,s)] == 0)
      			{
	      			for(int o = 0; o < s; o++)
		      		{
		      			for(int l = 0; l < s; l++)
					{
						data[y+o][x+l] = 200;
					}
		      		}
      			}
      			else 
	      		{
        			for(int o = 0; o < s; o++)
        			{
              				for(int l = 0; l < s; l++)
                			{
                        			data[y+o][x+l] = 55;
	                		}
        	      		}
      			}
    		}
  	}
 
  /* write the whole data array to ppm file in one step */
  /* create new file, give it a name and open it in binary mode */
  fp = fopen(filename, "wb");
  /* write header to the file */
  fprintf(fp, "P5\n %d\n %d\n %d\n", x_max, y_max,
          MaxColorComponentValue);
  /* write image data bytes to the file */
  fwrite(data, sizeof(data), 1, fp);
  fclose(fp);
  printf("OK - file %s saved\n", filename);
  return 0;
}


int ile(int y, int s)
{
	int n = 0;
	while(y > 1 && y % s == 0)
	{
		n++;
		y -= s;
	}

	return n;
}
