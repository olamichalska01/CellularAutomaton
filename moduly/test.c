#include <stdio.h>
 int main() {
        const int dimx = 800; 
        const int dimy = 400;
        int i, j;
        FILE * fp = fopen("first.ppm", "ab+"); /* b - tryb binarny */
        fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);
        for(j=0; j<dimy/2; ++j){
          for(i=0; i < dimx; ++i){         
                        static unsigned char color[3];
                        color[0]=0; /* red */
                        color[1]=0; /* green */
                        color[2]=0; /* blue */
                        fwrite(color,1,3,fp);
                }
        }

	for(j = dimy/2; j < dimy; ++j)
	{
		for(i = 0; i < dimx; ++i)
		{
			static unsigned char color[3];
                        color[0]=255; /* red */
                        color[1]=255; /* green */
                        color[2]=255; /* blue */
                        fwrite(color,1,3,fp);
		}
	}

        fclose(fp);
        return 0;
 }
