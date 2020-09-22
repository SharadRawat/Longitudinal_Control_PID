#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "include/i_controller.h"

class Controller : public IController
{
public:
    Controller(double intergral_gain, double derivative_gain, double proportional_gain);
    ~Controller();

    ParamType GetParams() override;

private:
    double error_{};
    double intergral_gain_{};
    double derivative_gain_{};
    double proportional_gain_{};
};

#endif /* CONTROLLER_CONTROLLER_H */