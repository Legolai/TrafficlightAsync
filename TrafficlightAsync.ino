#include "trafficlight.h"

#define D13 13
#define D12 12
#define D11 11
#define D10 10
#define D9 9
#define D8 8


unsigned long myTime;

Trafficlight light1(D13, D12, D11, myTime);
Trafficlight light2(D10, D9, D8, myTime);
Trafficlight *trafficlights[2] = {&light1, &light2};



void setup() {
  // put your setup code here, to run once:
  light1.setOtherLight(light2);
  light2.setOtherLight(light1);
  light1.setState(1);
  Serial.begin(9600);
  for (auto trafficlight : trafficlights) {
    trafficlight->setPinsMode();
    trafficlight->lightControl();
  }
}

void loop() {
  myTime = millis();
  // put your main code here, to run repeatedly:
  for (auto trafficlight : trafficlights) {
    trafficlight->lightSequance();
  }

}
