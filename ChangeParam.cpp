#include "ChangeParam.h"

ChangeParam::ChangeParam(Regulator& regulator, Regulator::Param param,
                         Regulator::UpdateDirection updateDirection)
  : Action{regulator}, param{param}, updateDirection{updateDirection} {}

void ChangeParam::execute() {
  if (param == Regulator::Param::R)
    regulator.updateR(updateDirection);
  else
    regulator.updateU(updateDirection);
}
