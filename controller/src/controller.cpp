#include "include/controller.h"

Controller::Controller(double intergral_gain, double derivative_gain, double proportional_gain) : intergral_gain_(intergral_gain), derivative_gain_(derivative_gain), proportional_gain_(proportional_gain) {}

Controller::~Controller() {}

ParamType Controller::GetParams()
{
    return std::make_tuple(proportional_gain_, intergral_gain_, derivative_gain_);
}