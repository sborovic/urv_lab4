#include "Timer.h"
#include "Regulator.h"
#include "UI.h"

/*
   Initializations
*/
#define INTERRUPT_PERIOD 20
#define PRINT_PERIOD 500
volatile bool interruptFlag = 0, printFlag = 0;
Timer timer{INTERRUPT_PERIOD, PRINT_PERIOD, interruptFlag, printFlag};
// Lepo ponasanje: {Kp = 0.3, Ti = 750}, {Kp = 0.2, Ti = 1000}, {Kp = 0.1, Ti = 1500}
#define Kp 0.3
#define Ti 750
#define START_R 10

Regulator regulator{Kp, Ti, INTERRUPT_PERIOD, START_R, Regulator::Mode::AUTO};

UI ui{regulator};

void setup() {
  Serial.begin(9600);
  timer.setup();
  ui.setup();
}

ISR(TIMER1_COMPA_vect) {
  timer.handleInterrupt();
}

void loop() {
  ui.run();
  if (interruptFlag) {
    regulator.update();
    interruptFlag = 0;
  }
  if (printFlag) {
    ui.updateLCD();
    printFlag = 0;
  }
}
