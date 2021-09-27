#include "trafficlight.h"
#include <Arduino.h>

Trafficlight::Trafficlight(int _pins[]) {
  *pins = _pins;
};

Trafficlight::Trafficlight(int _RPin, int _YPin, int _GPin) {
  RPin = _RPin;
  YPin = _YPin;
  GPin = _GPin;
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
  if (state == 0 || state == 1) {
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
  for (int i = 0; i < 4; i++) {
    lightControl();
    nextState();
    delay(1000);
  }
  checkState();
  lightControl();
  delay(1000);
};

void Trafficlight::setState(int _state) {
  state = _state;
}
void Trafficlight::nextState() {
  state++;
}

void Trafficlight::checkState() {
  if (state == 4) {
    state = 0;
  }
}

Trafficlight::~Trafficlight() {};
