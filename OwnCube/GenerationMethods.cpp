#include "SPI.h"
class GenerationMethods{
  private:
    uint8_t cube[9][8];
  public:
    void setVoxel(uint8_t x, uint8_t y, uint8_t z) {
      cube[z][y] |= (0x01 << x);
    }
    void clearCube() {
      for (uint8_t z = 0; z < 8; z++) {
        for (uint8_t y = 0; y < 8; y++) {
          cube[z][y] = 0;
        }
      }
    }
    void renderCube() {
      for (uint8_t z = 0; z < 9; z++) {
        digitalWrite(SS, LOW);
        SPI.transfer(0x01 << z);
        for (uint8_t y = 0; y < 8; y++) {
          SPI.transfer(cube[z][y]);
        }
        digitalWrite(SS, HIGH);
      }
    }
      
};