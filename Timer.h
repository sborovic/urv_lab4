#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer {
  public:
    static int const TIMER_PERIOD;
    Timer(int Ts, int Ps, volatile bool& interruptFlag, volatile bool& printFlag); // Timer period and Print period (in ms)
    void setup();
    void handleInterrupt();
  private:
    uint16_t interruptCnt, printCnt;
    const int interruptGoal, printGoal;
    volatile bool &interruptFlag, &printFlag;
};


#endif
