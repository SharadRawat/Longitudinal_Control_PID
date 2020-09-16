#include <gtest/gtest.h>
#include "include/controller.h"

TEST(Constructor, GivenAnObject_ExpectFalse)
{
    Controller unit{};
    bool result{unit.success};

    EXPECT_TRUE(result);
}
