# M5Stack Atom: IR Send, LED Light Demo
A very simple LED light controller with a synchronised Atom button LED.

You need this library too:
https://github.com/crankyoldgit/IRremoteESP8266

I used IR Dump V3 on an Arduino with a RF receiver to discover that the remote control for the light used the NEC format.              
I made a note of some colors, and the "On" and "Off" key.
Note that the only value returned from IRDump is the RAW VALUE. Not the channel/ID as these are also included in the short "raw value". (They're embedded in some bits of the bytes of the raw value, so aren't obviously within the raw data values! This led me astray for a bit, as I wondered how I was supposed to send them to the relevant device!)

When you come to find the values of your own remote controls, note that these lines of information aren't needed from the IR Dump program, as they're contained in the "data" line at the bottom:
uint32_t address = 0x0;             
uint32_t command = 0x1;        

...... are in here:                  
uint64_t data = 0xFF807F;         

Demo: https://www.youtube.com/watch?v=lZ-aN4xiOvA

Light: https://www.amazon.co.uk/gp/product/B094NGFXTX/

M5Stack Atom Lite: https://shop.m5stack.com/products/atom-lite-esp32-development-kit



![20210902_113955](https://user-images.githubusercontent.com/1586332/131835960-ce7c9353-8980-467d-a2c9-7573dfb75346.jpg)



