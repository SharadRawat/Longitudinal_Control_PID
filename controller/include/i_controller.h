#ifndef I_CONTROLLER_CONTROLLER_H
#define I_CONTROLLER_CONTROLLER_H

#include <tuple>

class IController
{
public:
    virtual ~IController(){};

    virtual void CalculateError(double sensor_velocity) = 0;

    virtual void AccumulateError() = 0;

    virtual double GetDeltaError() = 0;

    virtual void CalculateControlOutput(double sensor_velocity) = 0;
};

#endif /* I_CONTROLLER_CONTROLLER_H */