#ifndef SENDVOXELS_H
#define SENDVOXELS_H

#include "GenerationMethods.h"
class SendVoxels : public GenerationMethods{
  private:
    uint8_t selX = 0;
    uint8_t selY = 0;
    uint8_t selZ = 0;
    uint8_t sendDirection = 0;
    bool sending = false;
  public:
    SendVoxels();
    void sendDrawVoxels();
};
#endif