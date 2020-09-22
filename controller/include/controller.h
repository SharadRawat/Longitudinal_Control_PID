#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "include/i_controller.h"

class Controller : public IController
{
public:
    Controller(double intergral_gain, double derivative_gain, double proportional_gain, double referenced_velocity, double sensor_velocity);
    ~Controller();

    void CalculateError() override;

    ParamType GetParams();

    double GetError();

private:
    double error_{};
    double intergral_gain_{};
    double derivative_gain_{};
    double proportional_gain_{};
    double referenced_velocity_{};
    double sensor_velocity_{};
};

#endif /* CONTROLLER_CONTROLLER_H */