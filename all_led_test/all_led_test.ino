#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN         D6
#define NUMPIXELS   240


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.show();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<NUMPIXELS; i++){
    
    pixels.setPixelColor(i, pixels.Color(50, 50, 50));
    Serial.println(i);
    pixels.show();
    delay(20);
  }
  pixels.clear();
  pixels.show();
}
