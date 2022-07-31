/*
* Copyright 2022 Jayne Atkinson
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge, publish, distribute,
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*
*/


/* Example program for VGA Framebuffer driver */

//#include <errno.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
//#include <libopencm3/stm32/timer.h>
//#include <libopencm3/cm3/nvic.h>
//#include <libopencm3/stm32/spi.h>
//#include <libopencm3/stm32/dma.h>


#include "init.h"
#include "defines.h"
#include "vga.h"



int main (void)
{
  uint32_t y;  

  hw_setup();
  vga_clear();

  vga_set_cursor(0,0);
  vga_puts("STM32 Video Driver v0.1  (c)2022 J Atkinson M0JNE");
  vga_set_cursor(0, 2); 
  vga_puts("Video Resolution 800 x 600, 60Hz");                 

  // Plot a few points at the extremes
  vga_plot(400,0);
  vga_plot(400,599);
  vga_plot(0,300);
  vga_plot(799,300);
while(1);
 
}