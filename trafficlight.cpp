#include "trafficlight.h"
#include <Arduino.h>


Trafficlight::Trafficlight(int _RPin, int _YPin, int _GPin) {
  RPin = _RPin;
  YPin = _YPin;
  GPin = _GPin;
};

void Trafficlight::setOtherLight(Trafficlight &_otherLight) {
  otherLight = &_otherLight;
};

void Trafficlight::setPinsMode() {
  for (auto pin : pins) {
    pinMode(*pin, OUTPUT);
  }
};

void Trafficlight::turnAllOn() {
  for (auto pin : pins) {
    digitalWrite(*pin, HIGH);
  }
};

void Trafficlight::turnAllOff() {
  for (auto pin : pins) {
    digitalWrite(*pin, LOW);
  }
};

void Trafficlight::lightControl() {
  turnAllOff();
  if (state == 0 || state == 1 || state == 4) {
    digitalWrite(RPin, HIGH);
  }
  if (state == 1 || state == 3) {
    digitalWrite(YPin, HIGH);
  }
  if (state == 2) {
    digitalWrite(GPin, HIGH);
  }
};

void Trafficlight::lightSequance() {
  if (otherLight->getState() == 0) {
    nextState();
    checkState();
    lightControl();
  }
};

void Trafficlight::setState(int _state) {
  state = _state;
}

void Trafficlight::nextState() {
  curruntTime = millis();
  if (curruntTime - prevTime > 2000){
     state++;
     prevTime = curruntTime;
  }
}

int Trafficlight::getState() {
  return state;
}

void Trafficlight::checkState() {
  if (state == 5) {
    state = 0;
  }
}

Trafficlight::~Trafficlight() {};
