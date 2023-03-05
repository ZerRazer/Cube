#ifndef PLANEBOING_H
#define PLANEBOING_H
#include "GenerationMethods.h"
#define PLANE_BOING_TIME 220

class PlaneBoing{
  private:
  GenerationMethods gen;
  uint8_t planePosition = 0;
  uint8_t planeDirection = 0;
  bool looped = false;

  public:
  PlaneBoing();
  void drawPlaneBoing();
  void PlaneBoing::setPlane(uint8_t axis, uint8_t i);
};
#endif