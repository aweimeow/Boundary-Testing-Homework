#include "gtest/gtest.h"
#include "triangle.h"


TEST(TriangleTypeTest, WeakNormalTest) {
    // Weak Normal Equivalence Class Testing
    // Valid Value: 0 < value <= 200

    EXPECT_EQ(TRIANGLE_EQUALATERAL, CheckTriangleType(1, 1, 1));
    EXPECT_EQ(TRIANGLE_EQUALATERAL, CheckTriangleType(100, 100, 100));
    EXPECT_EQ(TRIANGLE_EQUALATERAL, CheckTriangleType(200, 200, 200));
    
    EXPECT_EQ(TRIANGLE_ISOSCELES, CheckTriangleType(1, 100, 100));
    EXPECT_EQ(TRIANGLE_ISOSCELES, CheckTriangleType(100, 200, 200));
    
    EXPECT_EQ(TRIANGLE_SCALENE, CheckTriangleType(100, 125, 150));

    EXPECT_EQ(TRIANGLE_RIGHTTRIANGLE, CheckTriangleType(120, 160, 200));

    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(1, 100, 150));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(50, 50, 200));
}

TEST(TriangleTypeTest, WeakRobustTest) {
    // Weak Robust Equivalence Class Testing
    // Some Invalid Data: Only one attribute will be invalid

    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(-1, 100, 100));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(100, -1, 100));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(100, 100, -1));
    
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(120, 120, 201));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(120, 201, 120));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(201, 120, 120));
}

TEST(TriangleTypeTest, StrongNormalTest) {
    // Strong Normal Equivalence Class Testing

    EXPECT_EQ(TRIANGLE_EQUALATERAL, CheckTriangleType(60, 60, 60));
    EXPECT_EQ(TRIANGLE_RIGHTTRIANGLE, CheckTriangleType(60, 80, 100));
    EXPECT_EQ(TRIANGLE_SCALENE, CheckTriangleType(60, 70, 80));
    EXPECT_EQ(TRIANGLE_ISOSCELES, CheckTriangleType(60, 100, 100));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(60, 60, 120));
}

TEST(TriangleTypeTest, StrongRobustTest) {
    // Strong Robust Equivalence Class Testing

    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(-1, -1, -1));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(-1, -1, 100));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(-1, 100, -1));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(100, -1, -1));

    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(201, 201, 201));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(150, 201, 201));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(201, 150, 201));
    EXPECT_EQ(TRIANGLE_INVALID, CheckTriangleType(201, 201, 150));
}
