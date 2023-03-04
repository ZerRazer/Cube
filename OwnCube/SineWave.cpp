#include "SPI.h"
#include <Arduino.h>
#include <SPI.h>
#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5

// define number of iterations
#define ITERATIONS 400
class SineWave{
  private:
    uint8_t cube[8][8];
    int timer = 0;
    bool loading = true;
  public:
    SineWave(){

    }
    void drawSineWave() {
        if (loading) {
          clearCube();
          loading = false;
        }
        timer++;
        if (timer > 300) {
          timer = 0;
          // loop through the iteration counter
          for (int i = 0; i < ITERATIONS; i++) {
            // loop through all 64 x and y coordinates
            for (int x = 0; x < 8; x++) {
              for (int y = 0; y < 8; y++) {
                // calculate distance between center of the cube and x/y coordinate
                double dx = x - CENTER_X;
                double dy = y - CENTER_Y;
                double distance = sqrt(dx * dx + dy * dy);

                // calculate z coordinate using sin() based on distance from center and iteration counter
                double z = CENTER_Z + sin((distance + i) * 0.2) * 3;
                // cast coordinates to integers and set voxel in cube
                // determine the position in the cube array based on the smoothed x, y, and z coordinates
                double smoothX = x + (sin((i / (double)ITERATIONS) * 2 * PI) * 1.5);
                double smoothY = y + (sin((i / (double)ITERATIONS) * 2 * PI) * 1.5);
                double smoothZ = z + (cos((i / (double)ITERATIONS) * 2 * PI) * 1.5);
            
                // check if the smoothed position is within the bounds of the cube
                if (smoothX >= 0 && smoothX < 8 && smoothY >= 0 && smoothY < 8 && smoothZ >= 0 && smoothZ < 8) {
                // set the voxel at the smoothed position in the cube
                  setVoxel((uint8_t)round(smoothX), (uint8_t)round(smoothY), (uint8_t)round(smoothZ));
                }
                renderCube();
              }
            }
            clearCube();
          }
        }
    }
    void clearCube() {
      for (uint8_t z = 0; z < 8; z++) {
        for (uint8_t y = 0; y < 8; y++) {
          cube[z][y] = 0;
        }
      }
  }
  void renderCube() {
    for (uint8_t z = 0; z < 8; z++) {
      digitalWrite(SS, LOW);
      SPI.transfer(0x01 << z);
      for (uint8_t y = 0; y < 8; y++) {
        SPI.transfer(cube[z][y]);
      }
      digitalWrite(SS, HIGH);
    }
  }

  void setVoxel(uint8_t x, uint8_t y, uint8_t z) {
    cube[z][y] |= (0x01 << x);
  } 
}; 
