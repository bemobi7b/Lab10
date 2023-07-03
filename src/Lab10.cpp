/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Rich/CTD2023/Lab10/src/Lab10.ino"
void setup();
void loop();
#line 1 "c:/Users/Rich/CTD2023/Lab10/src/Lab10.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

#define LEDPIN D5

void setup()
{
  Serial.begin(9600);
  Serial.isConnected();
  Serial.available();
  while (!Serial.isConnected())
  {
  }
  Serial1.begin(9600);
  // Serial1.isConnected();
  Serial1.available();
  // while(!Serial1.isConnected()){}
  pinMode(LEDPIN, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    char value = Serial.read();
    byte byteValue = value;
    Serial.println(value);
    Serial1.print(value);
  }
  if (Serial1.available() > 0){
    byte byteNewValue = Serial1.read();
    Serial.println(byteNewValue);
    if (byteNewValue == 48){
      digitalWrite(LEDPIN, LOW);
    }
    if (byteNewValue == 49){
      digitalWrite(LEDPIN, HIGH);
    }
    if (byteNewValue == 88){
      Serial.println("Wrong button, dummy.");
    }
  }
}