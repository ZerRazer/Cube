#ifndef SINEWAVE_H
#define SINEWAVE_H

#include <Arduino.h>
#include <SPI.h>
#include "GenerationMethods.h"

#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5

// define number of iterations
#define ITERATIONS 185
class SineWave{
  private:
    GenerationMethods gen;
    int timer = 0;
    double dx, dy, distance;
    bool loading = true;
    bool rotating = false;
    
  public:
    SineWave(bool rotating);
    void drawSineWave();
};
#endif
