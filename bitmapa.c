#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

#define _height 600
#define _width 800
#define _bitsperpixel 24
#define _planes 1
#define _compression 0
#define _pixelbytesize _height*_width*_bitsperpixel/8
#define _filesize _pixelbytesize+sizeof(bitmap)
#define _xpixelpermeter 0x130B //2835, 72 DPI
#define _ypixelpermeter 0x130B //2835, 72 DPI
#define pixel 0xFF

#pragma pack(push, 1)

typedef struct
{
	uint32_t dibheadersize;
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bitsperpixel;
	uint32_t compression;
	uint32_t imagesize;
	uint32_t ypixelpermeter;
	uint32_t xpixelpermeter;
	uint32_t numcolorspallette;
	uint32_t mostimpcolor;
} bitmapinfoheader;

typedef struct
{
	fileheader fileheader;
	bitmapinfoheader bitmapinfoheader;
} bitmap;

#pragma pack(pop)

int main(int argc, char **argv)
{
	FILE *fp = fopen("test.bmp", "wb");

	bitmap *pbitmap = (bitmap*)calloc(1, sizeof(bitmap));
	uint8_t *pixelbuffer = (uint8_t*)malloc(_pixelbytesize);

	strcpy(pbitmap -> fileheader.signature, "BM");

	pbitmap -> fileheader.filesize = _filesize;
	pbitmap -> fileheader.fileoffset_to_pixelarray = sizeof(bitmap);
	pbitmap -> bitmapinfoheader.dibheadersize = sizeof(bitmapinfoheader);
	
	
	return 0;
}




