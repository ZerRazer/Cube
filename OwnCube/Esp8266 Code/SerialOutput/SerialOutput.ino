#include<SoftwareSerial.h>
SoftwareSerial SUART(D3, D4); //SRX = D3, STX = D4

void setup()
{
  Serial.begin(115200);
  SUART.begin(9600);
}

void loop()
{
  SUART.print('B');
  delay(1000);
}