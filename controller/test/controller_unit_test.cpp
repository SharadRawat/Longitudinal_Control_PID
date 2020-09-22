#include <gtest/gtest.h>
#include "include/controller.h"

TEST(Constructor, GivenAnObject_ExpectFalse)
{
    // Given
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    double ref_vel{40.8};
    double sensed_vel{41};

    // When
    Controller unit{Ki, Kd, Kp, ref_vel, sensed_vel};

    // Then
    auto [proportional_gain, integral_gain, derivative_gain] = unit.GetParams();
    auto tolerance{std::numeric_limits<double>::epsilon()};

    EXPECT_NEAR(proportional_gain, Kp, tolerance);
    EXPECT_NEAR(derivative_gain, Kd, tolerance);
    EXPECT_NEAR(integral_gain, Ki, tolerance);
}

TEST(CalculateError, GivenReferenceVelocityAndSensedVelocity_ExpectCorrectError)
{
    // Given
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    double ref_vel{40.8};
    double sensed_vel{41};
    double expected_error{-0.2};
    Controller unit{Ki, Kd, Kp, ref_vel, sensed_vel};

    // When
    unit.CalculateError();

    // Then
    auto error{unit.GetError()};
    auto tolerance{std::numeric_limits<double>::epsilon()};

    EXPECT_NEAR(error, expected_error, 100 * tolerance);
}