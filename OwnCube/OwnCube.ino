#include <SPI.h>
#include <math.h>
#include "SineWave.cpp"
// define center of the cube
#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5
int timer = 0;
// define number of iterations
#define ITERATIONS 200

SineWave sine;
uint8_t cube[8][8];
bool loading = true;

void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  sine.drawSineWave();
}

