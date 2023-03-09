#include <SPI.h>
#include <math.h>
#include "SineWave.h"
#include "PlaneBoing.h"
#include "CubeJump.h"
#include "Rain.h"
#include "SendVoxels.h"
#include "WoopWoop.h"
#include "GenerationMethods.h"
#include "Glow.h"

#define BUTTON_PIN 2
#define TOTAL_EFFECTS 3

//Defines all effects you can use
#define TOTAL_EFFECTS 7
#define SINEWAVE 0
#define PLANEBOING 1
#define CUBEJUMP 2
#define RAIN 3
#define SEND_VOXELS 4
#define WOOP_WOOP 5
#define GLOW 6

//creates Object of the Effects to get access to the methods(Create only once!)
SineWave sine = new SineWave(false);
PlaneBoing plane;
CubeJump cube;
Rain raining;
SendVoxels voxels;
WoopWoop woop;
Glow glow;

//RotatingSineWave rotateSin;
uint8_t currentEffect;
int timer = 0;
void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  //Serial.begin(9600);
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
      case RAIN: raining.reset(); break;
      case SEND_VOXELS: voxels.reset(); break;
      case WOOP_WOOP: woop.reset(); break;
      case GLOW: glow.reset(); break;
      default: sine.reset();
    }
    currentEffect++;
    if (currentEffect == TOTAL_EFFECTS) {
      currentEffect = 0;
    }
  }
}
void loop() {
  switch (currentEffect) {
    case SINEWAVE: sine.drawSineWave(); break;
    case PLANEBOING: plane.drawPlaneBoing(); break;
    case CUBEJUMP: cube.drawCubeJump(); break;
    case RAIN: raining.drawRain(); break;
    case SEND_VOXELS: voxels.sendDrawVoxels(); break;
    case WOOP_WOOP: woop.drawWoopWoop(); break;
    case GLOW: glow.drawGlow(); break;
    default: sine.drawSineWave();
  }
  
}

