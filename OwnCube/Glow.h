#ifndef GLOW_H
#define GLOW_H

#include "GenerationMethods.h"

class Glow : public GenerationMethods{
  private:
    bool glowing;
    uint16_t glowCount = 0;
    uint8_t selX = 0;
    uint8_t selY = 0;
    uint8_t selZ = 0;
    uint8_t sendDirection = 0;
    bool sending = false;


  public:
    Glow();
    void drawGlow();
};
#endif