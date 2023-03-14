#include "Text.h"

Text::Text(){

}

void Text::drawText(String text){
  if (loading) {
    clearCube();
    charPosition = -1;
    charCounter = 0;
    loading = false;
  }
  timer++;
  if (timer > TEXT_TIME) {
    timer = 0;

    shift(POS_Z);
    charPosition++;
    if (charPosition == 7) {
      charCounter++;
      if (charCounter > text.length() - 1) {
          charCounter = 0;
      }
      charPosition = 0;
    }
    if(charPosition == 0){
      for(int i = 0; i < 8; i++){
        int numberPosition = text.charAt(charCounter) - 65;
        cube[i][7] = alphabet[numberPosition][i];
        Serial.println(alphabet[numberPosition][i]);
      }
    }
  }
  renderCube();
}