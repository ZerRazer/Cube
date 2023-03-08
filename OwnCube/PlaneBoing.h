#ifndef PLANEBOING_H
#define PLANEBOING_H
#include "GenerationMethods.h"

class PlaneBoing : public GenerationMethods{
  private:
  uint8_t planePosition = 0;
  uint8_t planeDirection = 0;
  bool looped = false;

  public:
  PlaneBoing();
  void drawPlaneBoing();
  void setPlane(uint8_t axis, uint8_t i);
};
#endif