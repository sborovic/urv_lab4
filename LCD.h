#ifndef LCD_H
#define LCD_H

#include "Arduino.h"
#include "Regulator.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCD {
  public:
    LCD();
    void setup();
    void displayAll(Regulator regulator);
    void displayMode(Regulator::Mode mode);
  private:
    LiquidCrystal_I2C lcd;
    void displayParam(Regulator::Param p, float num);
    void displayDefault();
    char output[8];
};

#endif
