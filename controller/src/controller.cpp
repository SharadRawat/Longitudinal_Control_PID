#include "include/controller.h"

Controller::Controller(uint64_t intergral_gain, uint64_t derivative_gain, uint64_t proportional_gain) : intergral_gain_(intergral_gain), derivative_gain_(derivative_gain), proportional_gain_(proportional_gain) {}

Controller::~Controller() {}

ParamType Controller::GetParams()
{
    return std::make_tuple(0, 0, 0);
}