
#include <Adafruit_NeoPixel.h>

#define PIN 6   // input pin Neopixel is attached to

#define NUMPIXELS      64 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // Initialize the NeoPixel library.
  Serial.begin(9600);
  pixels.begin();
  // create an array to hold positions
   // set in groups of 8
}
int rowLength = 8;
void loop() {
  
  // put your main code here, to run repeatedly:
    for(uint16_t t=0; t<NUMPIXELS/rowLength; t++){
      for (int i=0; i < rowLength; i++) {
        int currentNeoPixel = i + t*8;
        int red = pow(1.0905,currentNeoPixel);
        
      
      
    
Serial.println(red);  
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(currentNeoPixel, pixels.Color(red, 0, 0));

      // This sends the updated pixel color to the hardware.
      pixels.show();
      }}
}
