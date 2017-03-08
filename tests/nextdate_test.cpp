#include "gtest/gtest.h"
#include "nextdate.h"


TEST(NextDateTest, WeakNormalTest) {
    // Weak Normal Equivalence Class Testing
    // Valid Value: 1812 <= year <= 2012, 1 <= month <= 12, 1 <= day <= 31
    EXPECT_EQ(Date(2000, 1, 2), Date(2000, 1, 1).nextdate());
    EXPECT_EQ(Date(2000, 2, 29), Date(2000, 2, 28).nextdate());
    EXPECT_EQ(Date(2000, 3, 1), Date(2000, 2, 29).nextdate());
    EXPECT_EQ(Date(2001, 1, 1), Date(2000, 12, 31).nextdate());
    EXPECT_EQ(Date(2000, 10, 31), Date(2000, 10, 30).nextdate());
}

TEST(NextDateTest, WeakRobustTest) {
    // Weak Robust Equivalence Class Testing
    // Some Invalid Data: Only one attribute will be invalid

    EXPECT_EQ(Date(), Date(1811, 1, 1).nextdate());
    EXPECT_EQ(Date(), Date(2013, 1, 1).nextdate());
    EXPECT_EQ(Date(), Date(1812, 0, 1).nextdate());
    EXPECT_EQ(Date(), Date(2012, 13, 1).nextdate());
    EXPECT_EQ(Date(), Date(1812, 1, 0).nextdate());
    EXPECT_EQ(Date(), Date(2012, 1, 32).nextdate());
    EXPECT_EQ(Date(), Date(2012, 2, 30).nextdate());
}

TEST(NextDateTest, StrongNormalTest) {
    // Strong Normal Equivalence Class Testing
    
    EXPECT_EQ(Date(2000, 2, 2), Date(2000, 2, 1).nextdate());
    EXPECT_EQ(Date(2000, 3, 1), Date(2000, 2, 29).nextdate());
    EXPECT_EQ(Date(2000, 3, 31), Date(2000, 3, 30).nextdate());
    EXPECT_EQ(Date(2000, 4, 1), Date(2000, 3, 31).nextdate());
    EXPECT_EQ(Date(2000, 5, 1), Date(2000, 4, 30).nextdate());
    EXPECT_EQ(Date(2000, 6, 1), Date(2000, 5, 31).nextdate());
    EXPECT_EQ(Date(2000, 7, 1), Date(2000, 6, 30).nextdate());
    EXPECT_EQ(Date(2000, 8, 1), Date(2000, 7, 31).nextdate());
    EXPECT_EQ(Date(2000, 9, 1), Date(2000, 8, 31).nextdate());
    EXPECT_EQ(Date(2000, 10, 1), Date(2000, 9, 30).nextdate());
    EXPECT_EQ(Date(2000, 11, 1), Date(2000, 10, 31).nextdate());
    EXPECT_EQ(Date(2000, 12, 1), Date(2000, 11, 30).nextdate());
    EXPECT_EQ(Date(2001, 1, 1), Date(2000, 12, 31).nextdate());

    EXPECT_EQ(Date(2004, 2, 29), Date(2004, 2, 28).nextdate());
}

TEST(NextDateTest, StrongRobustTest) {
    // Strong Robust Equivalence Class Testing

    EXPECT_EQ(Date(), Date(1811, 0, 0).nextdate());
    EXPECT_EQ(Date(), Date(1811, 0, 1).nextdate());
    EXPECT_EQ(Date(), Date(1811, 1, 0).nextdate());
    EXPECT_EQ(Date(), Date(1812, 0, 0).nextdate());

    EXPECT_EQ(Date(), Date(2013, 13, 32).nextdate());
    EXPECT_EQ(Date(), Date(2013, 13, 31).nextdate());
    EXPECT_EQ(Date(), Date(2013, 12, 32).nextdate());
    EXPECT_EQ(Date(), Date(2012, 13, 32).nextdate());
}

