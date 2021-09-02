#ifndef CHANGE_MODE_H
#define CHANGE_MODE_H

#include "Action.h"
#include "Regulator.h"
#include "LED.h"
#include "Button.h"
#include "LCD.h"
#include "ButtonsActions.h"

class ChangeMode : public Action {
  public:
    ChangeMode(Regulator& r, LED(&leds)[3], Button(&buttons)[3], LCD& lcd, ButtonsActions& changeR, ButtonsActions& changeU);
    void execute();
    void makeMode();
  private:
    Regulator& r;
    LED(&leds)[3];
    Button(&buttons)[3];
    LCD& lcd;
    ButtonsActions &changeR, &changeU;
};

#endif
