#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"

// user defined image from gimp (save as c-source, RGB565)
#include "emblem_25th.c"

#define DISP_X 320
#define DISP_Y 240

typedef int filter[5][5];

filter mean =
{ {10,10,10,10,10},
  {10,10,10,10,10},
  {10,10,10,10,10},
  {10,10,10,10,10},
  {10,10,10,10,10}};

filter gauss =
{ { 1, 4, 5, 4, 1},
  { 4,16,24,16, 4},
  { 6,24,36,24, 6},
  { 4,16,24,16, 4},
  { 1, 4, 5, 4, 1}};

filter sobelx =
{ { -5,-11, 0,11,  5},
  {-21,-42, 0,42, 21},
  {-32,-64, 0,64, 32},
  {-21,-42, 0,42, 21},
  { -5,-11, 0,11,  5}};

filter sobely =
{ { -5,-21,-32,-21, -5},
  {-11,-42,-64,-42,-11},
  {  0,  0,  0,  0,  0},
  { 11, 42, 64, 42, 11},
  {  5, 21, 32, 21,  5}};

filter laplace=
{ {  0,-64,-64,-64,  0},
  {-64,  0,128,  0,-64},
  {-64,128,255,128,-64},
  {-64,  0,128,  0,-64},
  {  0,-64,-64,-64,  0}};

unsigned short int read_pixel(int x, int y){
	return IORD_16DIRECT(SRAM_0_BASE,((y<<9) +x)*2);
}
void write_pixel(int x, int y, unsigned short int pix){
	IOWR_16DIRECT(SRAM_0_BASE, ((y<<9)+x)*2, pix);
}
unsigned short int get_image(int x, int y){
	int idx = y*320+x;
	return ((unsigned short int*)gimp_image.pixel_data)[idx];
}

int rgb_to_gray(unsigned short int pin){
  int r,g,b,gray;
  /*  Y = 0.298912 * r + 0.586611 * g + 0.114478 * b;
   *        76/256            150/256        29/256
   *  Each color component will be 6-bits           */
  r = (pin>>10) & 0x3e;
  g = (pin>> 5) & 0x3f;
  b = (pin<< 1) & 0x3e;
  gray = (76*r+150*g+29*b);
  /* scaling factor will be 1/256 */
  return gray;
}

unsigned short int gray_to_rgb(int pin){
  int pout;
  pout = ((pin & 0x3e)<<10)
        |((pin & 0x3f)<< 5)
        |((pin & 0x3e)>> 1);
  return pout;
}

void filter_image(filter f){
	int x,y;
	int s=2; /* filter_size/2 */
	for(y=0;y<DISP_Y;++y){
		  for(x=0;x<DISP_X;++x){
			  int sum=0;
        /* write a code for liner filtering in here
         * Scaling factor should be 1/26636=1/2^16 during calculation.
         * After the calculation, apply 16-bit right shift to sum.
         * Absolution and saturation logics are also required.
         */
			  write_pixel(x,y,gray_to_rgb(sum));
		  }
	  }
}

void raw_image(){
  int x,y;
  for(y=0;y<240;++y){
	  for(x=0;x<320;++x){
		  write_pixel(x,y,get_image(x,y));
	   }
  }
}

void grayscale_image(){
  int x,y;
  for(y=0;y<240;++y){
	  for(x=0;x<320;++x){
      unsigned short int pout;
      int pin, gray;
      pin = get_image(x,y);
      gray = rgb_to_gray(pin);
      /* scaling factor of gray is 1/256 */
      pout = gray_to_rgb((unsigned short int)(gray >> 8));
		  write_pixel(x,y,pout);
	   }
  }
}


int main(){
	int sw,psw;
	psw = 0;
	alt_up_pixel_buffer_dma_dev *pixel_buf_dev;

	pixel_buf_dev = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0");
	if(pixel_buf_dev==NULL)
		alt_putstr("Error: could not poen pixel buffer device \n");
	else
		alt_putstr("Opened pixel buffer device \n");

	/* Event loop to select filters. */
	while (1){
		sw= IORD_32DIRECT(SW_BASE, 0);
		if(psw!=sw){
			/*do selection*/
			switch (sw){
			case  1: grayscale_image(); break;
			case  2: filter_image(mean); break;
      /* add code in here */
			default: raw_image();
			}
		}
		psw = sw;
	}
	return 0;
}