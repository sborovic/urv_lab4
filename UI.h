#ifndef UI_H
#define UI_H

#include "Arduino.h"
#include "Button.h"
#include "LED.h"
#include "ChangeMode.h"
#include "LCD.h"
#include "ChangeParam.h"
#include "ButtonsActions.h"

class UI {
  public:
    UI(Regulator& regulator);
    void setup();
    void run();
    void updateLCD();
  private:
    static const int numOfButtons = 3;
    static const int numOfLeds = 3;
    Button buttons[numOfButtons];
    LED leds[numOfLeds];
    ChangeMode changeMode;
    Regulator& regulator;
    LCD lcd;
    ButtonsActions changeR, changeU;
};

#endif
