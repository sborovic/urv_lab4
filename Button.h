#ifndef BUTTON_H
#define BUTTON_H

#include "Action.h"
#include "Arduino.h"

class Button {
  public:
    Button(byte pin, Action* action);
    void setup();
    bool pressed();
    void executeAction();
    void executeActionIfPressed();
    void setAction(Action* action);
  private:
    static const int debounceDelay;
    byte pin;
    unsigned long lastDebounceTime;
    int buttonState, lastButtonState;
    Action* action;
};

#endif
