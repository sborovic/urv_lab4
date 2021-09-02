#ifndef ACTION_H
#define ACTION_H

#include "Regulator.h"

class Action {
  public:
    Action(Regulator& regulator);
    virtual void execute() = 0;
  protected:
    Regulator& regulator;
};

#endif
