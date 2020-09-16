#ifndef I_CONTROLLER_CONTROLLER_H
#define I_CONTROLLER_CONTROLLER_H

#include <tuple>

using ParamType = std::tuple<uint64_t,uint64_t,int64_t>;

class IController
{
    public:
        IController() = default;
        ~IController() = default;

        virtual ParamType GetParams() = 0;
        virtual void SetParams(ParamType& param) = 0;
};

#endif /* I_CONTROLLER_CONTROLLER_H */