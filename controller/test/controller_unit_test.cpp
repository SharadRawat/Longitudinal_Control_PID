#include <gtest/gtest.h>
#include "include/controller.h"

namespace
{
    auto tolerance{std::numeric_limits<double>::epsilon()};
}

TEST(Constructor, GivenAnObject_ExpectFalse)
{
    // Given
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    double ref_vel{40.8};
    double sensed_vel{41};
    double delta_time{0.10};

    // When
    Controller unit{delta_time, Ki, Kd, Kp, ref_vel, sensed_vel};

    // Then
    auto [proportional_gain, integral_gain, derivative_gain] = unit.GetParams();

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
    double delta_time{0.10};
    double expected_error{-0.2};
    
    Controller unit{delta_time, Ki, Kd, Kp, ref_vel, sensed_vel};

    // When
    unit.CalculateError();

    // Then
    auto error{unit.GetError()};

    EXPECT_NEAR(error, expected_error, 100 * tolerance);
}

TEST(AccumulateError, GivenReferenceVelocityAndSensedVelocity_ExpectCorrectError)
{
    // Given
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    double ref_vel{40.8};
    double sensed_vel{41};
    double delta_time{0.10};
    double expected_error{-0.4};
    
    Controller unit{delta_time, Ki, Kd, Kp, ref_vel, sensed_vel};
    unit.CalculateError();

    // When
    unit.AccumulateError();
    unit.AccumulateError();

    // Then
    auto error{unit.GetAccumulateError()};

    EXPECT_NEAR(error, expected_error, 100 * tolerance);
}

TEST(GetDeltaError, GivenReferenceVelocityAndSensedVelocity_ExpectCorrectError)
{
    // Given
    double Kp{15.26};
    double Kd{110.8};
    double Ki{0.04};
    double ref_vel{40.8};
    double sensed_vel{41};
    double delta_time{0.10};
    double expected_error{-2.0};
    
    Controller unit{delta_time, Ki, Kd, Kp, ref_vel, sensed_vel};
    unit.CalculateError();

    // When
    auto error{unit.GetDeltaError()};

    // Then
    EXPECT_NEAR(error, expected_error, 1000 * tolerance);
}

TEST(CalculateControlOutput, GivenParamsAndError_ExpectCorrectControlOutput)
{
    // Given
    double Kp{10};
    double Kd{5};
    double Ki{1};
    double ref_vel{40};
    double sensed_vel{41};
    double delta_time{0.10};
    double expected_result{-61};
    
    Controller unit{delta_time, Ki, Kd, Kp, ref_vel, sensed_vel};

    // Whendd
    unit.CalculateControlOutput();

    // Given
    auto result{unit.GetControlOutput()};

    EXPECT_NEAR(result, expected_result, tolerance);
}