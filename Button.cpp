#include "Button.h"

const int Button::debounceDelay = 50;

Button::Button(byte pin, Action* action) : pin{pin}, lastButtonState{LOW}, lastDebounceTime{0}, action{action} {}

void Button::setup() {
  pinMode(pin, INPUT);
}

bool Button::pressed() {
  int reading = digitalRead(pin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) return true;
    }
  }
  lastButtonState = reading;
  return false;
}

void Button::executeAction() {
  if (action != nullptr) action->execute();
}
void Button::executeActionIfPressed() {
  if (pressed()) executeAction();
}
void Button::setAction(Action* action) {
  this->action = action;
}
