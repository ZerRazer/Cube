
#include <Arduino.h>
#include <SPI.h>
#include "GenerationMethods.cpp"
#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5

// define number of iterations
#define ITERATIONS 400
class SineWave{
  private:
    GenerationMethods gen;
    int timer = 0;
    bool loading = true;
    
  public:
    SineWave(){

    }
    void drawSineWave() {
        if (loading) {
          gen.clearCube();
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
                double z = CENTER_Z + sin((distance + i) * 0.3) * 3.5;
                // cast coordinates to integers and set voxel in cube
                // determine the position in the cube array based on the smoothed x, y, and z coordinates
                double smoothX = x;
                double smoothY = y;
                double smoothZ = z;
            
                // check if the smoothed position is within the bounds of the cube
                if (smoothX >= 0 && smoothX < 8 && smoothY >= 0 && smoothY < 8 && smoothZ >= 0 && smoothZ < 8) {
                // set the voxel at the smoothed position in the cube
                  gen.setVoxel((uint8_t)round(smoothX), (uint8_t)round(smoothY), (uint8_t)round(smoothZ));
                }
                gen.renderCube();
              }
            }
            gen.clearCube();
          }
        }
    }
};

