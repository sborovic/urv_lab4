#include "LED.h"

LED::LED(byte pin) : pin {pin}, state{LOW} {}

void LED::setup() {
  pinMode(pin, OUTPUT);
}

void LED::on() {
  state = HIGH;
  digitalWrite(pin, state);
}

void LED::off() {
  state = LOW;
  digitalWrite(pin, state);
}

void LED::toggle() {
  if (state == HIGH) off();
  else on();
}
