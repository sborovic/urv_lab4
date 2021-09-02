#include "LCD.h"

const struct {
  byte x, y;
} pointR{.x = 9, .y = 0}, pointY{.x = 9, .y = 1}, pointU{.x = 0, .y = 1};

LCD::LCD() : lcd{0x27, 16, 2} {}

void LCD::setup() {
  lcd.init();
  lcd.backlight();
  displayDefault();
}

void LCD::displayDefault() {
  lcd.setCursor(pointY.x, pointY.y);
  lcd.print("Y=");
  lcd.setCursor(pointU.x, pointU.y);
  lcd.print("U=");
}

void LCD::displayParam(Regulator::Param p, float num) {
  char floatStr[5];
  if (num >= 100)
    sprintf(floatStr, "%4.d", 100);
  else
    dtostrf(num, 4, 1, floatStr);
  int x, y;
  switch (p) {
    case Regulator::Param::R:
      x = pointR.x + 2;
      y = pointR.y;
      break;
    case Regulator::Param::Y:
      x = pointY.x + 2;
      y = pointY.y;
      break;
    case Regulator::Param::U:
      x = pointU.x + 2;
      y = pointU.y;
      break;
  }
  lcd.setCursor(x, y);
  lcd.print(floatStr);
}

void LCD::displayAll(Regulator regulator) {
  if (regulator.mode == Regulator::Mode::AUTO)
    displayParam(Regulator::Param::R, regulator.R);
  displayParam(Regulator::Param::U, regulator.U);
  displayParam(Regulator::Param::Y, regulator.Y);
}

void LCD::displayMode(Regulator::Mode mode) {
  lcd.setCursor(0, 0);
  if (mode == Regulator::Mode::AUTO) {
    lcd.print("AUTO");
    lcd.setCursor(pointR.x, pointR.y);
    lcd.print("R=");
  } else {
    lcd.print("MAN ");
    lcd.setCursor(pointR.x, pointR.y);
    char blankSpace[8];
    memset(blankSpace, ' ', 7);
    blankSpace[7] = '\0';
    lcd.print(blankSpace);
  }
}
