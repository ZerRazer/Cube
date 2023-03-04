#include <SPI.h>
#include <math.h>
#include "SineWave.cpp"

SineWave sine;

void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  sine.drawSineWave();
}

