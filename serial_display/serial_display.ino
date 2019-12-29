#include "elements.h"

#define LED_PIN 6
#define PANEL_SIZE_W 10
#define PANEL_SIZE_H 24
//#define BRIGHTNESS 50

Adafruit_NeoPixel strip(PANEL_SIZE_W*PANEL_SIZE_H, LED_PIN, NEO_GRBW + NEO_KHZ800);
MatrixDisplay matrix(LED_PIN, PANEL_SIZE_W, PANEL_SIZE_H);
void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  
}

void loop() {
  

	
}
