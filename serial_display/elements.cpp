#include "elements.h"

void MatrixDisplay::show(){
  for(uint8_t i=0; i<SIZE_W; i++){
    for(uint8_t j=0; j<SIZE_H; j++){
      rgb_color c = color_table[i][j];
      if(i%2 == 0){
        strip.setPixelColor(i*SIZE_H + j, strip.Color(c.r, c.g, c.b));
      }else{
        strip.setPixelColor((i+1)*SIZE_H - j, strip.Color(c.r, c.g, c.b));
      }
    }
  }
  strip.show();
}

void MatrixDisplay::showSingleColor(rgb_color &color){
  uint32_t c = ((uint32_t)color.r << 16) | ((uint32_t)color.g <<  8) | color.b;
  for(uint8_t i=0; i<SIZE_H*SIZE_W; i++){
    strip.setPixelColor(i, c);
  }
  strip.show();
}
