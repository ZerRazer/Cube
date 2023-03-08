#include "SineWave.h"

SineWave::SineWave(bool rotating){
  //RotatingSineWave or a normal SineWave
  this->rotating = rotating;
}
void SineWave::drawSineWave() {
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
        for (int z = 0; z < 8; z++) {
          // calculate distance between center of the cube and x/y coordinate
          this->dx = x - CENTER_X;
          this->dy = z - CENTER_Y;
          this->distance = sqrt(dx * dx + dy * dy) * 5;   
          
          // calculate z coordinate using sin() based on distance from center and iteration counter
          double y = CENTER_Z + sin((this->distance + i) * 0.1 ) * 3.5;
          // cast coordinates to integers and set voxel in cube
          // determine the position in the cube array based on the smoothed x, y, and z coordinates
          double smoothX = x;
          double smoothY = y;
          double smoothZ = z;
          if(y > 7){
            smoothY = 7;
          }
          else{
            smoothY = y;
          }
        
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
    this->counter += 0.1;
  }
}
void SineWave::setRotating(bool rotating){
  this->rotating = rotating;
}



