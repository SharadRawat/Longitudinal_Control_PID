#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "include/i_controller.h"

class Controller : public IController
{
public:
    Controller(uint64_t intergral_gain, uint64_t derivative_gain, uint64_t proportional_gain);
    ~Controller();

    ParamType GetParams() override;

private:
    uint64_t error_{};
    uint64_t intergral_gain_{};
    uint64_t derivative_gain_{};
    uint64_t proportional_gain_{};
};

#endif /* CONTROLLER_CONTROLLER_H */