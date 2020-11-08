#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "include/i_controller.h"

class Controller : public IController
{
public:
    using ParamType = std::tuple<double, double, double>;

    Controller(double delta_time, double intergral_gain, double derivative_gain, double proportional_gain, double referenced_velocity);
    ~Controller();

    void CalculateError(double sensor_velocity) override;

    void AccumulateError() override;

    double GetDeltaError() override;

    void CalculateControlOutput(double sensor_velocity) override;

    ParamType GetParams();

    double GetError();

    double GetAccumulateError();

    double GetControlOutput();

private:
    double delta_time_{};
    double error_{};
    double accumulated_error_{};
    double previous_cycle_error_{};

    double intergral_gain_{};
    double derivative_gain_{};
    double proportional_gain_{};

    double referenced_velocity_{};
    double sensor_velocity_{};
    double control_output_{};
};

#endif /* CONTROLLER_CONTROLLER_H */