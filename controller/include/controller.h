#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "include/i_controller.h"

class Controller : public IController
{
    public:
        Controller(){success = true;}
        ~Controller(){};
        
    // private:
    bool success{false};

};

#endif /* CONTROLLER_CONTROLLER_H */