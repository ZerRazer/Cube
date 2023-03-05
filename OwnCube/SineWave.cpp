#include "SineWave.h"

SineWave::SineWave(bool rotating){
  //RotatingSineWave or a normal SineWave
  this->rotating = rotating;
}
void SineWave::drawSineWave() {
  if (gen.loading) {
    gen.clearCube();
    gen.loading = false;

  }
  gen.timer++;
  if (gen.timer > 300) {
    gen.timer = 0;
    // loop through the iteration counter
    for (int i = 0; i < ITERATIONS; i++) {
      // loop through all 64 x and y coordinates
      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
          // calculate distance between center of the cube and x/y coordinate
          this->dx = x - CENTER_X;
          this->dy = y - CENTER_Y;
          this->distance = sqrt(dx * dx + dy * dy) * 5;   
          
          // calculate z coordinate using sin() based on distance from center and iteration counter
          double z = CENTER_Z + sin((this->distance + i) * 0.1 ) * 3.5;
          // cast coordinates to integers and set voxel in cube
          // determine the position in the cube array based on the smoothed x, y, and z coordinates
          double smoothX = x;
          double smoothY = y;
          double smoothZ = z;
          if(z > 7){
            smoothZ = 7;
          }
          else{
            smoothZ = z;
          }
        
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
    this->counter += 0.1;
  }
}
void SineWave::setRotating(bool rotating){
  this->rotating = rotating;
}



