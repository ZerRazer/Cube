#include <SPI.h>
#include <math.h>
#include "SineWave.h"
#include "PlaneBoing.h"
#include "CubeJump.h"
#include "GenerationMethods.h"
//#include "RotatingSineWave.h"
#define BUTTON_PIN 5
#define TOTAL_EFFECTS 3

#define SINEWAVE 0
#define PLANEBOING 1
#define CUBEJUMP 2

GenerationMethods gen;
SineWave sine = new SineWave(false);
PlaneBoing plane;
CubeJump cube;



//RotatingSineWave rotateSin;

uint8_t currentEffect;
void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  currentEffect = 2;
}

void loop() {
  //Serial.println("Loop Anfang");
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("KNOPF GEDRÜCKT");
    gen.clearCube();
    gen.loading = true;
    gen.timer = 0;
    currentEffect++;
    if (currentEffect == TOTAL_EFFECTS) {
      currentEffect = 0;
    }
  }
  switch (currentEffect) {
    case SINEWAVE: sine.drawSineWave(); break;
    case PLANEBOING: plane.drawPlaneBoing(); break;
    case CUBEJUMP: cube.drawCubeJump(); break;
    default: sine.drawSineWave();
  }
}

