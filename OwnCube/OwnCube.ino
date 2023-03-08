#include <SPI.h>
#include <math.h>
#include "SineWave.h"
#include "PlaneBoing.h"
#include "CubeJump.h"
#include "GenerationMethods.h"
//#include "RotatingSineWave.h"
#define BUTTON_PIN 2
#define TOTAL_EFFECTS 3

#define SINEWAVE 0
#define PLANEBOING 1
#define CUBEJUMP 2

SineWave sine = new SineWave(false);
PlaneBoing plane;
CubeJump cube;
//RotatingSineWave rotateSin;
uint8_t currentEffect;
int timer = 0;
void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), change_mode, CHANGE);
  currentEffect = 0;
}
void change_mode(){
  //Debouncer
  if(millis() - timer> 2000){
    timer = 0;
  }
  if(timer == 0){
    timer = millis();
    Serial.println("KNOPF GEDRÜCKT");
    switch (currentEffect) {
      case SINEWAVE: sine.reset(); break;
      case PLANEBOING: plane.reset(); break;
      case CUBEJUMP: cube.reset(); break;
      default: sine.reset();
    }
    currentEffect++;
    if (currentEffect == 3) {
      currentEffect = 0;
    }
  }
}
void loop() {
  switch (currentEffect) {
    case SINEWAVE: sine.drawSineWave(); break;
    case PLANEBOING: plane.drawPlaneBoing(); break;
    case CUBEJUMP: cube.drawCubeJump(); break;
    default: sine.drawSineWave();
  }
  
}

