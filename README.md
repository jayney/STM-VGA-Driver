# STM32F4 VGA Driver

A simple driver for STM32F4xx devices to produce VGA output using minimal CPU time

This provides basic monochrome video output from a STM32F4 Microcontroller and was developed and tested on a Nucleo 446RE development board.
It will probably port to other F4 devices, subject to available resources, with little or no modification. YMMV with other families, especially "General Purpose" families such as F0/F3/L4 etc due to h/w differences, especially around the DMA resources

   Resources Used:
   
    ~7k Flash
    ~62k RAM
    Timer 2 - VSYNC          default PA5
    Timer 3 - HSYNC          default PA6
    SPI 1 MOSI - Video Out   default PB5
    DMA Controller 2 Stream 5, Channel 3

Compiles under PlatformIO, using the LibOpenCM3 framework.

Other 16 bit General Purpose timers should also work, as should other SPI modules, but these will need to be hard coded in the appropriate setup functions (I'm a part time bodge coder, certainly not good enough to allocate resources on the fly, a la Arduino). The main thing to be aware of, is that the HSYNC timer is used as the clock input to the VSYNC timer to ensure they always remain in sync with each other, so this needs to be accounted for if reallocating timers. 

The currently coded mode is 800x600, 1bpp, 37.878kHz Horizontal, 60Hz Vertical, 40MHz Pixel Clock.

Changing main clock, timer settings and some #defines will allow other resolutions. YMMV.
I've tested with a LG TV, with 33 Ohm resistors in series with the two Sync connections, and a 470 Ohm in series
with the output and one or more colour inputs. Ensure you KNOW what you are doing before connecting to a monitor.
I accept NO responsibility for any damage incurred to monitors/microcontrollers (especially CRTs!), nor for personal injury.
