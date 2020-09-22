#include <gtest/gtest.h>
#include "include/controller.h"

TEST(Constructor, GivenAnObject_ExpectFalse)
{
    uint64_t Kp{};
    uint64_t Kd{};
    uint64_t Ki{};
    Controller unit{Kp, Kd, Ki};

    auto params = unit.GetParams();

    EXPECT_EQ(std::get<0>(params), Kp);
}
