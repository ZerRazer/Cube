#include "GenerationMethods.h"

void GenerationMethods::setVoxel(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] |= (0x01 << x);
}
void GenerationMethods::clearVoxel(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] ^= (0x01 << x);
}

bool GenerationMethods::getVoxel(uint8_t x, uint8_t y, uint8_t z) {
  return (cube[7 - y][7 - z] & (0x01 << x)) == (0x01 << x);
}
void GenerationMethods::clearCube() {
    for (uint8_t z = 0; z < 8; z++) {
      for (uint8_t y = 0; y < 8; y++) {
        cube[z][y] = 0;
    }
  }
}
void GenerationMethods::renderCube() {
    for (uint8_t z = 0; z < 9; z++) {
      digitalWrite(SS, LOW);
      SPI.transfer(0x01 << z);
    for (uint8_t y = 0; y < 8; y++) {
      SPI.transfer(cube[z][y]);
    }
    digitalWrite(SS, HIGH);
  }
}
void GenerationMethods::shift(uint8_t dir) {

  if (dir == POS_X) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y][z] << 1;
      }
    }
  } else if (dir == NEG_X) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y][z] >> 1;
      }
    }
  } else if (dir == POS_Y) {
    for (uint8_t y = 1; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y - 1][z] = cube[y][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[7][i] = 0;
    }
  } else if (dir == NEG_Y) {
    for (uint8_t y = 7; y > 0; y--) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y - 1][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[0][i] = 0;
    }
  } else if (dir == POS_Z) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 1; z < 8; z++) {
        cube[y][z - 1] = cube[y][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[i][7] = 0;
    }
  } else if (dir == NEG_Z) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 7; z > 0; z--) {
        cube[y][z] = cube[y][z - 1];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[i][0] = 0;
    }
  }
}
void GenerationMethods::drawCube(uint8_t x, uint8_t y, uint8_t z, uint8_t s) {
  for (uint8_t i = 0; i < s; i++) {
    setVoxel(x, y + i, z);
    setVoxel(x + i, y, z);
    setVoxel(x, y, z + i);
    setVoxel(x + s - 1, y + i, z + s - 1);
    setVoxel(x + i, y + s - 1, z + s - 1);
    setVoxel(x + s - 1, y + s - 1, z + i);
    setVoxel(x + s - 1, y + i, z);
    setVoxel(x, y + i, z + s - 1);
    setVoxel(x + i, y + s - 1, z);
    setVoxel(x + i, y, z + s - 1);
    setVoxel(x + s - 1, y, z + i);
    setVoxel(x, y + s - 1, z + i);
  }
}
void GenerationMethods::reset(){
  loading = true;
  timer = 0;
  clearCube();
}
