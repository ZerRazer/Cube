#ifndef GENERATIONMETHODS_H
#define GENERATIONMETHODS_H

#define XAXIS 0
#define YAXIS 1
#define ZAXIS 2

#define POS_X 0
#define NEG_X 1
#define POS_Z 2
#define NEG_Z 3
#define POS_Y 4
#define NEG_Y 5

#include "SPI.h"
class GenerationMethods{
  private:
    uint8_t cube[10][8];
    bool loading = true;
  public:
    void setVoxel(uint8_t x, uint8_t y, uint8_t z);
    void clearCube();
    void renderCube(); 
    void shift(uint8_t dir);    
};
#endif