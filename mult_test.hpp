#ifndef __MULT_TEST_HPP
#define __MULT_TEST_HPP

#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Base* testOpOne = new Op(3);
    Base* testOpTwo = new Op(22.9);
    Base* test = new Mult(testOpOne, testOpTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 22.9 * 3);
}

TEST(MultTest, MultEvaluateNegative) {
    Base* testOpOne = new Op(-2.1);
    Base* testOpTwo = new Op(22.9);
    Base* test = new Mult(testOpOne, testOpTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -2.1 * 22.9);
}

TEST(MultTest, MultEvaluateZero) {
    Base* testOpOne = new Op(0);
    Base* testOpTwo = new Op(1.29);
    Base* test = new Mult(testOpOne, testOpTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 0 * 1.29);
}

TEST(MultTest, MultStringifyZeroAndPos) {
    Base* testOpOne = new Op(0);
    Base* testOpTwo = new Op(1.29);
    Base* test = new Mult(testOpOne, testOpTwo);
    EXPECT_TRUE(test->stringify() == "(0 * 1.29)");
}

TEST(MultTest, MultStringifyNegative) {
    Base* testOpOne = new Op(-12);
    Base* testOpTwo = new Op(1.29);
    Base* test = new Mult(testOpOne, testOpTwo);
    EXPECT_TRUE(test->stringify() == "(-12 * 1.29)");
}

#endif //__MULT_TEST_HPP__
