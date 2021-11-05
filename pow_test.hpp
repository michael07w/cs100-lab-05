#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "pow.hpp"

TEST(PowTest, PowEvaluateNonZero) {
    Base* opTestOne = new Op(1.5);
    Base* opTestTwo = new Op(3.5);
    Base* test = new Pow(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(),pow(1.5, 3.5));
}

TEST(PowTest, PowEvaluateNegative) {
    Op* opTestOne = new Op(-2.6);
    Op* opTestTwo = new Op(5.4);
    Base* test = new Pow(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), pow(-2.6, 5.4));
}

TEST(PowTest, PowEvaluateDoubleNegative) {
    Op* opTestOne = new Op(-0.12);
    Op* opTestTwo = new Op(-10.12);
    Base* test = new Pow(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), pow(-0.12, -10.12));
}

TEST(PowTest, PowEvaluateZero) {
     Op* opTestOne = new Op(5.1);
     Op* opTestTwo = new Op(0);
     Base* test = new Pow(opTestOne, opTestTwo);
     EXPECT_DOUBLE_EQ(test->evaluate(), pow(5.1, 0));
}

TEST(PowTest, PowStringifyZeroandPos) {
     Op* opTestOne = new Op(0);
     Op* opTestTwo = new Op(8.9);
     Base* test = new Pow(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(0 ** 8.9)");
}

TEST(PowTest, PowStringifyNeg) {
     Op* opTestOne = new Op(-14.8);
     Op* opTestTwo = new Op(1.7);
     Base* test = new Pow(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(-14.8 ** 1.7)");
}

#endif //__POW_TEST_HPP__
