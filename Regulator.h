#ifndef REGULATOR_H
#define REGULATOR_H

#include "Arduino.h"

class Regulator {
  public:
    enum class Mode {AUTO, MAN};
    enum class Param {R, U, Y};
    enum class UpdateDirection {UP, DOWN};
    Regulator(float Kp, float Ti, float Ts, float R, Mode mode);
    Mode toggleMode();
    void updateR(UpdateDirection updateDirection);
    void updateU(UpdateDirection updateDirection);
    void update();
    void print();
  private:
    static const float d = 0.5;
    const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
    const int analogOutPin = 11; // Analog output pin that the LED is attached to
    float Kp, Ti, Ts;
    float R, U, Y;
    float Ui;
    float e, Up;
    Mode mode;
    void updateParam(float& param, UpdateDirection updateDirection);
    void regulate();
    friend class ChangeMode;
    friend class LCD;
};

#endif
