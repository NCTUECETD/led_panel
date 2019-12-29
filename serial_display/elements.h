#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#ifndef _RGB_COLOR
#define _RGB_COLOR
  /*! A struct that can be used to represent colors.  Each field is a number
   * between 0 and 255 that represents the brightness of a component of the
   * color. */
typedef struct rgb_color
  {
    uint8_t r, g, b;
    rgb_color() {};
    rgb_color(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {};
  } rgb_color;
#endif

#ifndef _MATRIX_H
#define _MATRIX_H

class MatrixDisplay{
  Adafruit_NeoPixel strip;
  const uint8_t SIZE_W;
  const uint8_t SIZE_H;
  rgb_color **color_table;
public:
  MatrixDisplay(uint8_t led_pin, uint8_t size_w=10, uint8_t size_h=24):SIZE_W(size_w), SIZE_H(size_h){
    strip = Adafruit_NeoPixel(size_w*size_h, led_pin, NEO_GRBW + NEO_KHZ800);
    strip.begin();
    strip.show(); 

    color_table = new rgb_color*[SIZE_W];
    for(uint8_t i=0; i<SIZE_W; i++){
      color_table[i] = new rgb_color[SIZE_H];
    }
  }

  void show();
  void showSingleColor(rgb_color &color);
};

#endif
