#include<SoftwareSerial.h>
SoftwareSerial SUART(3, 4); //SRX = DPin-3, STX = DPin-4
#define LED_PIN 9

bool active = false;
void setup()
{
  Serial.begin(9600);
  SUART.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.print(" ");
}

void loop()
{
  byte n = SUART.available();
  if (n != 0)
  {
    char x = SUART.read();
    Serial.println(x);
    if(x == 'B'){ 
      if(active == false){
        digitalWrite(LED_PIN, HIGH);
        Serial.println(x);
        active = true;
      }
      else{
        digitalWrite(LED_PIN, LOW);
        Serial.println(x);
        active = false;
      }
    }
  }
  delay(1000);
}
