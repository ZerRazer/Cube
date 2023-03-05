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

#define RAIN_TIME 260
#define PLANE_BOING_TIME 220
#define SEND_VOXELS_TIME 140
#define WOOP_WOOP_TIME 350
#define CUBE_JUMP_TIME 200
#define GLOW_TIME 8
#define TEXT_TIME 300
#define CLOCK_TIME 500

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
    void drawCube(uint8_t x, uint8_t y, uint8_t z, uint8_t s);
};
#endif