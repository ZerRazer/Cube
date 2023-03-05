#ifndef SINEWAVE_H
#define SINEWAVE_H

#include "GenerationMethods.h"

#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5

// define number of iterations
#define ITERATIONS 185
class SineWave{
  private:
    GenerationMethods gen;
    double dx, dy, distance;
    bool rotating = false;
    double counter = 0;
    
  public:
    SineWave(bool rotating);
    void drawSineWave();
    void setRotating(bool rotating);
};
#endif
