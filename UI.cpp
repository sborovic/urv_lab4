#include "UI.h"

#define LED_LEFT 5
#define LED_CENTER 6
#define LED_RIGHT 7

#define BUTTON_LEFT 2
#define BUTTON_CENTER 3
#define BUTTON_RIGHT 4

UI::UI(Regulator& regulator)
  : leds{LED{LED_LEFT}, LED{LED_CENTER}, LED{LED_RIGHT}},
    regulator{regulator},
    lcd{LCD{}},
    changeR{.up = ChangeParam{regulator, Regulator::Param::R,
                              Regulator::UpdateDirection::UP},
            .down = ChangeParam{regulator, Regulator::Param::R,
                                Regulator::UpdateDirection::DOWN}},
    changeU{.up = ChangeParam{regulator, Regulator::Param::U,
                              Regulator::UpdateDirection::UP},
            .down = ChangeParam{regulator, Regulator::Param::U,
                                Regulator::UpdateDirection::DOWN}},
    changeMode{regulator, leds, buttons, lcd, changeR, changeU},
    buttons{Button{BUTTON_LEFT, nullptr}, Button{BUTTON_CENTER, &changeMode},
            Button{BUTTON_RIGHT, nullptr}}
{}

void UI::setup() {
  for (int i = 0; i < numOfLeds; i++) leds[i].setup();
  for (int i = 0; i < numOfButtons; i++) buttons[i].setup();
  lcd.setup();
  changeMode.makeMode();
}

void UI::run() {
  for (int i = 0; i < numOfButtons; i++) buttons[i].executeActionIfPressed();
}

void UI::updateLCD() {
  lcd.displayAll(regulator);
}
