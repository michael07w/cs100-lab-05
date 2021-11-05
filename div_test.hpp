#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Op* opTestOne = new Op(75);
    Op* opTestTwo = new Op(3.4);
    Base* test = new Div(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 75 / 3.4);
}

TEST(DivTest, DivEvaluateNegative) {
    Op* opTestOne = new Op(5.1);
    Op* opTestTwo = new Op(-3.4);
    Base* test = new Div(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 5.1 / -3.4);
}

TEST(DivTest, DivEvaluateDoubleNegative) {
    Op* opTestOne = new Op(-0.12);
    Op* opTestTwo = new Op(-100.1);
    Base* test = new Div(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -0.12 / -100.1);
}

// Need to implement an exception for divide by zero
TEST(DivTest, DivEvaluateZero) {
    Op* opTestOne = new Op(5.1);
    Op* opTestTwo = new Op(0);
    Base* test = new Div(opTestOne, opTestTwo);
 
    // test that exception is thrown
    EXPECT_THROW({
	try {
	    test->evaluate();
	}
	catch (const DivByZero& e) {
	    // test that exception message is correct
	    EXPECT_STREQ("Cannot divide by zero!", e.what());
	    throw;
	}
    }, DivByZero);
}

#endif //__DIV_TEST_HPP__
