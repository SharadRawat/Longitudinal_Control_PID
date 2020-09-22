#include <gtest/gtest.h>
#include "include/controller.h"

TEST(Constructor, GivenAnObject_ExpectFalse)
{
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    Controller unit{Ki, Kd, Kp};
    auto [proportional_gain, integral_gain, derivative_gain] = unit.GetParams();

    EXPECT_EQ(proportional_gain, Kp);
    EXPECT_EQ(derivative_gain, Kd);
    EXPECT_EQ(integral_gain, Ki);
}
