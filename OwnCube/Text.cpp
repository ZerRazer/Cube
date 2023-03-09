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

    shift(NEG_Z);
    text.toCharArray(this->text, sizeof(this->text));

    for(int i = 0; i < text.length(); i++){
      int numberPosition = this->text - 65;
      cube[i][0] = alphabet[numberPosition][i];
    }
  }
}