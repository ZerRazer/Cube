#ifndef WOOPWOOP_H
#define WOOPWOOP_H

#include "GenerationMethods.h"

class WoopWoop : public GenerationMethods{
  private:
    uint8_t cubeSize = 0;
    bool cubeExpanding = true;

  public:
    WoopWoop();
    void drawWoopWoop();
};
#endif