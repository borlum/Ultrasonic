#include "Ultrasonic.h"

Ultrasonic testSensor(48, 49, 50, true);

void setup() {

  Serial.begin(9600);
  testSensor.turnOn();

}

int foo;

void loop() {

  foo = testSensor.getDistance();

  Serial.println(foo);
  
}