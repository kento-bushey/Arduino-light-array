#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS      64 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int redColor = 0;
int greenColor = 0;
int blueColor = 0;
//determine linear function for increase intensity
float slope = 32;
float yintercept = 0;
//determine linear function for decrease intensity
float slope2 = 32;
float yintercept2 = 255;
// row length for the led matrix
int rowLength = 8;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
  // create an array to hold positions
 	// set in groups of 8
  

}

void loop() {
  for(uint16_t t=0; t<rowLength/2; t++){
    //setColor(t);

    for (int i=0; i < rowLength; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      //pixels.setPixelColor(i + t*8, pixels.Color(redColor, greenColor, blueColor));
		pixels.setPixelColor(i + t*8, i*(256/rowLength),0,0);
      	pixels.setPixelColor(i + t*8+rowLength*(rowLength/2), 0,0,i*(256/rowLength));
      // This sends the updated pixel color to the hardware.
      pixels.show();

    }
  }
    
}
