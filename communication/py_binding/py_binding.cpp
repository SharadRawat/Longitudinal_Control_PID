#include <boost/python.hpp>
#include "include/controller.h"


BOOST_PYTHON_MODULE(py_binding)
{
    using namespace boost::python;

    class_<Controller, boost::noncopyable>("controller", init<double, double, double, double, double>())
    .def("CalculateControlOutput", &Controller::CalculateControlOutput)
    .def("GetError", &Controller::GetError)
    .def("GetAccumulateError", &Controller::GetAccumulateError)
    .def("GetDeltaError", &Controller::GetDeltaError);
    
}