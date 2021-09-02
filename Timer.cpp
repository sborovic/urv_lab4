#include "Timer.h"

const int Timer::TIMER_PERIOD = 20; // Timer period equals 20ms

Timer::Timer(int Ts, int Ps, volatile bool& interruptFlag, volatile bool& printFlag)
  : interruptCnt{0}, printCnt{0}, interruptGoal{Ts / TIMER_PERIOD},
    printGoal{Ps / TIMER_PERIOD}, interruptFlag{interruptFlag}, printFlag{printFlag} {}

void Timer::setup() {
  cli(); // stop interrupts

  // set timer1 interrupt at 50Hz
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1 = 0;  // initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 312; // = (16*10^6) / (50*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei(); // allow interrupts
}
void Timer::handleInterrupt() {
  interruptCnt++;
  printCnt++;
  if (interruptCnt >= interruptGoal) {
    interruptFlag = 1;
    interruptCnt = 0;
  }
  if (printCnt >= printGoal) {
    printFlag = 1;
    printCnt = 0;
 
  }

}
