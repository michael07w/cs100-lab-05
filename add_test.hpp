#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
    Base* opTestOne = new Op(1.5);
    Base* opTestTwo = new Op(3.5);
    Base* test = new Add(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 1.5 + 3.5);
}

TEST(AddTest, AddEvaluateNegative) {
    Op* opTestOne = new Op(-2.6);
    Op* opTestTwo = new Op(5.4);
    Base* test = new Add(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -2.6 + 5.4);
}

TEST(AddTest, AddEvaluateDoubleNegative) {
    Op* opTestOne = new Op(-0.12);
    Op* opTestTwo = new Op(-10.12);
    Base* test = new Add(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -0.12 + -10.12);
}

TEST(AddTest, AddEvaluateZero) {
     Op* opTestOne = new Op(5.1);
     Op* opTestTwo = new Op(0);
     Base* test = new Add(opTestOne, opTestTwo);             
     EXPECT_DOUBLE_EQ(test->evaluate(), 5.1 + 0);
}

TEST(AddTest, AddStringifyZeroandPos) {
     Op* opTestOne = new Op(0);
     Op* opTestTwo = new Op(8.9);
     Base* test = new Add(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(0 + 8.9)");
}

TEST(AddTest, AddStringifyNeg) {
     Op* opTestOne = new Op(-14.8);
     Op* opTestTwo = new Op(1.7);
     Base* test = new Add(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(-14.8 + 1.7)");
}
                  		    			    	    	    	   
#endif //__ADD_TEST_HPP__
