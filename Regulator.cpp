#include "Regulator.h"

Regulator::Regulator(float Kp, float Ti, float Ts, float R, Mode mode)
  : Kp{Kp}, Ti{Ti}, Ts{Ts}, R{R}, U{0}, Y{0}, Ui{0}, mode{mode} {}

Regulator::Mode Regulator::toggleMode() {
  if (mode == Mode::AUTO) {
    mode = Mode::MAN;
  }
  else {
    mode = Mode::AUTO;
    Ui = U;
    R = Y;
  }
  return mode;
}
void Regulator::updateR(UpdateDirection updateDirection) {
  updateParam(R, updateDirection);
}
void Regulator::updateU(UpdateDirection updateDirection) {
  updateParam(U, updateDirection);
}
void Regulator::updateParam(float& param, UpdateDirection updateDirection) {
  if (updateDirection == UpdateDirection::UP) {
    param += d;
    if (param > 100) param = 100;
  } else {
    param -= d;
    if (param < 0) param = 0;

  }
}

void Regulator::update() {
  Y = analogRead(analogInPin) / 1023.0 * 100.0; //0-1023 (0V-5V)
  if (mode == Mode::AUTO) regulate();
  analogWrite(analogOutPin, U / 100.0 * 255.0); //0-255 (0V-5V)
}
void Regulator::print() {
  Serial.print("U = ");
  Serial.print(U);
  Serial.print(" Ui = ");
  Serial.print(Ui);
  Serial.print(" Up = ");
  Serial.print(Up);
  Serial.print(" e = ");
  Serial.println(e);
 
}


void Regulator::regulate() {
  e = R - Y;
  Up = Kp * e;
  float delta = Kp / Ti * Ts * e;
  Ui += delta;
  U = Up + Ui;
  if (U > 100) {
    U = 100;
    Ui -= delta;
  } else if (U < 0) {
    U = 0;
    Ui -= delta;
  }
}
