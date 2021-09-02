#include "ChangeMode.h"

ChangeMode::ChangeMode(Regulator& regulator, LED(&leds)[3], Button(&buttons)[3],
                       LCD& lcd, ButtonsActions& changeR, ButtonsActions& changeU)
  : Action{regulator},
    leds{leds},
    buttons{buttons},
    lcd{lcd},
    changeR{changeR},
    changeU{changeU}
{}

void ChangeMode::makeMode() {
  if (regulator.mode == Regulator::Mode::AUTO) {
    leds[0].on();
    leds[1].off();
    leds[2].on();
    buttons[0].setAction(&changeR.down);
    buttons[2].setAction(&changeR.up);
  } else {
    leds[0].off();
    leds[1].on();
    leds[2].off();
    buttons[0].setAction(&changeU.down);
    buttons[2].setAction(&changeU.up);
  }
  lcd.displayMode(regulator.mode);
}

void ChangeMode::execute() {
  regulator.toggleMode();
  makeMode();
}
