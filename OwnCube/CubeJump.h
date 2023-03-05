#ifndef CUBEJUMP_H
#define CUBEJUMP_H

#include "GenerationMethods.h"

class CubeJump{
  private:
    GenerationMethods gen;
    bool loading = true;
    int timer = 0;
    uint8_t xPos;
    uint8_t yPos;
    uint8_t zPos;
    uint8_t cubeSize = 0;
    bool cubeExpanding = true;
  public:
    CubeJump();  
    void drawCubeJump();

};
#endif