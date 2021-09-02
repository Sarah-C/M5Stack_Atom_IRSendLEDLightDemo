# M5Stack Atom: IR Send, LED Light Demo
A VERY simple LED light controller (just a fixed demo) with a synchronised Atom button LED.       
As the Atom changes its button color, the LED light changes to the same color in a repeating sequence.        
I found this setup was the easiest way to check I was using the IR Dump program and transmit code correctly!         

You need this library too:
https://github.com/crankyoldgit/IRremoteESP8266

I used IR Dump V3 (contained in the above library) on an Arduino with a RF receiver to discover that the remote control for the light used the NEC format.              
I made a note of some colors, and the "On" and "Off" key.                         
Note that the only value returned from IRDump is the DATA value. Not the address/command as these are also included in the slightly longer data value. (They're embedded in some bits of the bytes of the data value, so aren't obvious. This led me astray for a bit, as I wondered how I was supposed to send them to the relevant device!)

When you come to find the values of your own remote controls, note that these lines of information aren't needed from the IR Dump program, as they're contained in the "data" line at the bottom:             
uint32_t address = 0x0; << Ignore this line                 
uint32_t command = 0x1; << Ignore this line                  
...... are in here:                  
uint64_t data = 0xFF807F; << Just transmit this line's data        

Demo: https://www.youtube.com/watch?v=lZ-aN4xiOvA

Light: https://www.amazon.co.uk/gp/product/B094NGFXTX/

M5Stack Atom Lite: https://shop.m5stack.com/products/atom-lite-esp32-development-kit



![Atom Demo](https://user-images.githubusercontent.com/1586332/131835960-ce7c9353-8980-467d-a2c9-7573dfb75346.jpg)

![The light used](https://user-images.githubusercontent.com/1586332/131837809-d3c76dae-69fc-40ee-8dbc-53d3f6897f91.jpg)

