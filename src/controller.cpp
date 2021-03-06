#include "include/controller.h"
#include <cmath>

Controller::Controller(double delta_time, double intergral_gain, double derivative_gain, double proportional_gain, double referenced_velocity) : delta_time_(delta_time), intergral_gain_(intergral_gain), derivative_gain_(derivative_gain), proportional_gain_(proportional_gain), referenced_velocity_(referenced_velocity){}

Controller::~Controller() {}

void Controller::CalculateError(double sensor_velocity)
{   
    sensor_velocity_ = sensor_velocity;
    error_ = referenced_velocity_ - sensor_velocity_;
}

void Controller::AccumulateError()
{
    accumulated_error_ += error_;
}

double Controller::GetDeltaError()
{
    auto delta_error{(error_ - previous_cycle_error_) / delta_time_};
    return delta_error;
}

void Controller::CalculateControlOutput(double sensor_velocity)
{
    CalculateError(sensor_velocity);
    AccumulateError();

    auto [kp, ki, kd] = GetParams();
    control_output_ = kd * GetDeltaError() + ki * accumulated_error_ + kp * error_;

    previous_cycle_error_ = error_;
}

Controller::ParamType Controller::GetParams()
{
    return std::make_tuple(proportional_gain_, intergral_gain_, derivative_gain_);
}

double Controller::GetError()
{
    return error_;
}

double Controller::GetAccumulateError()
{
    return accumulated_error_;
}

double Controller::GetControlOutput()
{
    return control_output_;
}