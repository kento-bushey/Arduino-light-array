#include <Adafruit_NeoPixel.h>

#define PIN 6	 // input pin Neopixel is attached to

#define NUMPIXELS      64 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int redColor = 0;
int greenColor = 0;
int blueColor = 0;
//determine linear function for increase intensity
float slope = 2;
float yintercept = -1;
//determine linear function for decrease intensity
float slope2 = 2;
float yintercept2 = -1;
// row length for the led matrix
int rowLength = 8;

void setup() {
  // Initialize the NeoPixel library.
  Serial.begin(9600);
  pixels.begin();
  // create an array to hold positions
 	// set in groups of 8
}
void loop() {
  for(uint16_t t=0; t<NUMPIXELS/rowLength; t++){
    for (int i=0; i < rowLength; i++) {
      int currentNeoPixel = i + t*8;
      if (currentNeoPixel <= 32){
        redColor = pow(slope, i) + yintercept;
        blueColor = 0;
        greenColor =0;
      }else {
        redColor = 0;
        blueColor = pow(slope, i)+ yintercept;
        greenColor =0;
      }
	  Serial.println(redColor);  
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(currentNeoPixel, pixels.Color(redColor, greenColor, blueColor));

      // This sends the updated pixel color to the hardware.
      pixels.show();

    }
  }
}
