#ifndef LED_H
#define LED_H

#include "Arduino.h"

class LED {
  public:
    LED(byte pin);
    void setup();
    void on();
    void off();
    void toggle();
  private:
    byte pin;
    int state;
};

#endif
