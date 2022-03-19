#include "gtest/gtest.h"
#include "cube.h"
extern int cube_test();
TEST(cube_test_UT, ok) {
    EXPECT_EQ (cube_test(),0);
}