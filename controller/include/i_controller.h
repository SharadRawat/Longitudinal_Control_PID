#ifndef I_CONTROLLER_CONTROLLER_H
#define I_CONTROLLER_CONTROLLER_H

#include <tuple>

using ParamType = std::tuple<uint64_t, uint64_t, int64_t>;

class IController
{
public:
    virtual ~IController(){};

    virtual ParamType GetParams() = 0;
};

#endif /* I_CONTROLLER_CONTROLLER_H */