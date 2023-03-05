#include <SPI.h>
#include <math.h>
#include "SineWave.h"
//#include "RotatingSineWave.h"

SineWave sine = new SineWave(false);
//RotatingSineWave rotateSin;

void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
}

void loop() {
  //rotateSin.drawRotatingSineWave();
  sine.drawSineWave();
}

