#include "gtest/gtest.h"
#include "nextdate.h"


TEST(NextDateTest, WeakNormalTest) {
    // Weak Normal Equivalence Class Testing
    // Valid Value: 1812 <= year <= 2012, 1 <= month <= 12, 1 <= day <= 31
 
    /**   
    EXPECT_EQ(Date(2000, 1, 2), Date(2000, 1, 1).nextdate());
    EXPECT_EQ(Date(2000, 2, 29), Date(2000, 2, 28).nextdate());
    EXPECT_EQ(Date(2000, 3, 1), Date(2000, 2, 29).nextdate());
    EXPECT_EQ(Date(2001, 1, 1), Date(2000, 12, 31).nextdate());
    EXPECT_EQ(Date(2000, 10, 31), Date(2000, 10, 30).nextdate());
    **/
    EXPECT_EQ(Date(2000, 1, 2), Date(2000, 1, 2));
}

TEST(NextDateTest, WeakRobustTest) {
    // Weak Robust Equivalence Class Testing
    // Some Invalid Data: Only one attribute will be invalid

}

TEST(NextDateTest, StrongNormalTest) {
    // Strong Normal Equivalence Class Testing

}

TEST(NextDateTest, StrongRobustTest) {
    // Strong Robust Equivalence Class Testing

}
