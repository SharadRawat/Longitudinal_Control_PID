#include "include/controller.h"

Controller::Controller(double intergral_gain, double derivative_gain, double proportional_gain, double referenced_velocity, double sensor_velocity) : intergral_gain_(intergral_gain), derivative_gain_(derivative_gain), proportional_gain_(proportional_gain), referenced_velocity_(referenced_velocity), sensor_velocity_(sensor_velocity) {}

Controller::~Controller() {}

void Controller::CalculateError()
{
    error_ = referenced_velocity_ - sensor_velocity_;
}

ParamType Controller::GetParams()
{
    return std::make_tuple(proportional_gain_, intergral_gain_, derivative_gain_);
}

double Controller::GetError()
{
    return error_;
}