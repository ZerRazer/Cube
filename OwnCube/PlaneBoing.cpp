#include "PlaneBoing.h"

PlaneBoing::PlaneBoing(){

}
void PlaneBoing::drawPlaneBoing(){
 if (gen.loading) {
    Serial.println("Es geht in PlaneBoing rein");
    gen.clearCube();
    uint8_t axis = random(0, 3);
    planePosition = random(0, 2) * 7;
    setPlane(axis, planePosition);
    if (axis == XAXIS) {
      if (planePosition == 0) {
        planeDirection = POS_X;
      } else {
        planeDirection = NEG_X;
      }
    } else if (axis == YAXIS) {
      if (planePosition == 0) {
        planeDirection = POS_Y;
      } else {
        planeDirection = NEG_Y;
      }
    } else if (axis == ZAXIS) {
      if (planePosition == 0) {
        planeDirection = POS_Z;
      } else {
        planeDirection = NEG_Z;
      }
    }
    gen.timer = 0;
    looped = false;
    gen.loading = false;
  }

  gen.timer++;
  if (gen.timer > PLANE_BOING_TIME) {
    Serial.println("Es hat den Timer auf 0 gesetzt");
    gen.timer = 0;
    gen.shift(planeDirection);
    if (planeDirection % 2 == 0) {
      planePosition++;
      if (planePosition == 7) {
        if (looped) {
          gen.loading = true;
        } else {
          planeDirection++;
          looped = true;
        }
      }
    } else {
      planePosition--;
      if (planePosition == 0) {
        if (looped) {
          gen.loading = true;
        } else {
          planeDirection--;
          looped = true;
        }
      }
    }
    
  }
  gen.renderCube();
}
void PlaneBoing::setPlane(uint8_t axis, uint8_t i) {
  for (uint8_t j = 0; j < 8; j++) {
    for (uint8_t k = 0; k < 8; k++) {
      if (axis == XAXIS) {
        gen.setVoxel(i, j, k);
      } else if (axis == YAXIS) {
        gen.setVoxel(j, i, k);
      } else if (axis == ZAXIS) {
        gen.setVoxel(j, k, i);
      }
    }
  }
}