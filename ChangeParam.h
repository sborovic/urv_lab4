#ifndef CHANGE_PARAM_H
#define CHANGE_PARAM_H

#include "Action.h"
#include "Regulator.h"

class ChangeParam : public Action {
  public:
    ChangeParam(Regulator& regulator, Regulator::Param param,
                Regulator::UpdateDirection updateDirection);
    void execute();

  private:
    Regulator::Param param;
    Regulator::UpdateDirection updateDirection;
};

#endif
