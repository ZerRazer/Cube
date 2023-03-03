#include <SPI.h>
#include <math.h>

// define center of the cube
#define CENTER_X 3.5
#define CENTER_Y 3.5
#define CENTER_Z 3.5

// define number of iterations
#define ITERATIONS 200

byte cube[8][8] = {
  // Layer 1
  {0b00000000,  // Row 1
   0b00000000,  // Row 2
   0b00000000,  // Row 3
   0b00000000,  // Row 4
   0b00000000,  // Row 5
   0b00000000,  // Row 6
   0b00000000,  // Row 7
   0b00000000}, // Row 8

  // Layer 2
  {0b00000000,  // Row 1
   0b00000000,  // Etc ...
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 3
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 4
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 5 
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 6
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 7
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000},

  // Layer 8
  {0b00000000, 
   0b00000000, 
   0b00000000, 
   0b00000000,
   0b00000000,
   0b00000000, 
   0b00000000, 
   0b00000000}
};
bool loading = true;

void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
}

void loop() {
  drawSineWave();
  renderCube();
}

void drawSineWave() {
  if (loading) {
    clearCube();
    loading = false;
  }
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
        double z = CENTER_Z + sin(distance + i * 0.1);

        // cast coordinates to integers and set voxel in cube
        uint8_t voxelX = (uint8_t)x;
        uint8_t voxelY = (uint8_t)y;
        uint8_t voxelZ = (uint8_t)round(z);
        if (voxelZ >= 0 && voxelZ < 8) {
          setVoxel(voxelX, voxelY, voxelZ);
        }
      }
    }
  }
}

void setVoxel(uint8_t x, uint8_t y, uint8_t z) {
  cube[z][y] |= (0x01 << x);
}

void renderCube() {
  for (uint8_t z = 0; z < 8; z++) {
    digitalWrite(SS, LOW);
    SPI.transfer(0x01 << z);
    for (uint8_t y = 0; y < 8; y++) {
      SPI.transfer(cube[z][y]);
    }
    digitalWrite(SS, HIGH);
  }
}

void clearCube() {
  for (uint8_t z = 0; z < 8; z++) {
    for (uint8_t y = 0; y < 8; y++) {
      cube[z][y] = 0;
    }
  }
}