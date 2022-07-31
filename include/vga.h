/* This provides basic monochrome video output from a STM32F4 Microcontroller  

   It was developed and tested on a Nucleo 446RE development board.
   It will probably port to other F4 devices, subject to available resources,
   with little or no modification. YMMV with other families, especially 
   "General Purpose" families such as F0/F3/L4 etc due to h/w differences

   Resources Used:
     ~7k Flash
     ~62k RAM
     Timer 2 - VSYNC          default PA5
     Timer 3 - HSYNC          default PA6
     SPI 1 MOSI - Video Out   default PB5
     DMA Controller 2 Stream 5, Channel 3

     Compiles under PlatformIO, using the LibOpenCM3 framework.

  Other 16 bit General Purpose timers should also work, and other SPI modules
  should work too. But this will need to be hard coded in the appropriate 
  setup functions. I am not a very good coder, certainly not good enough to 
  allocate resources on the fly, a la Arduino.

  The currently coded mode is 800x600, 1bpp, 37.878kHz Horizontal, 60Hz Vertical, 40MHz Pixel Clock.
  Changing main clock, timer settings and some #defines will allow other resolutions. YMMV.

  I've tested with a LG TV, with 33 Ohm resistors in series with the two Sync connections, and a 470 Ohm in series
  with the output and one or more colour inputs. Ensure you KNOW what you are doing before connecting to a monitor.

  I accept NO responsibility for any damage incurred to monitors/microcontrollers (especially CRTs!), nor for personal injury.


  (c) 2022 Jayne Atkinson @emzerojayney

  Version History:
  v0.1  29/03/2022  Initial Release

*/

/*
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */



#ifndef __VGA_H
#define __VGA_H


#define HSYNC_PERIOD  2112     // HSync Clock Speed = 90MHz/31.5kHz
#define HSYNC_PULSE   220      // HSync Pulse Width = 3.84us / (1/90MHz)
#define H_BACKPORCH   409      // Basically 0.5 x Hsync pulse (but includes length of hsync)
#define VSYNC_PERIOD  628      // VSync is clocked from HSync, so 525 lines = 1 frame
#define VSYNC_PULSE   4        // First 2 lines of frame = sync pulse
#define LINE_SIZE     100      // 8 pixels per byte = 568 Pixels
#define LINES         600

#define V_SYNC_PIN  GPIO5 // Port PA5
#define H_SYNC_PIN  GPIO6 // Port PA6



void vga_setup(void);
void vga_clear(void);
void vga_scroll(void);
void vga_set_cursor(uint8_t x, uint8_t y);
void write_char(char character);
void vga_puts(char *string);
void vga_putlong(uint32_t value);
void vga_plot(uint16_t x, uint16_t y);

#endif
