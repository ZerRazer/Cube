#ifndef GENERATIONMETHODS_H
#define GENERATIONMETHODS_H

#include "SPI.h"
class GenerationMethods{
  private:
    uint8_t cube[10][8];
  public:
    void setVoxel(uint8_t x, uint8_t y, uint8_t z);
    void clearCube();
    void renderCube();     
};
#endif