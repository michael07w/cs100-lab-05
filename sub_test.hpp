#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Base* opTestOne = new Op(1.5);
    Base* opTestTwo = new Op(3.5);
    Base* test = new Sub(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), 1.5 - 3.5);
}

TEST(SubTest, SubEvaluateNegative) {
    Op* opTestOne = new Op(-2.6);
    Op* opTestTwo = new Op(5.4);
    Base* test = new Sub(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -2.6 - 5.4);
}

TEST(SubTest, SubEvaluateDoubleNegative) {
    Op* opTestOne = new Op(-0.12);
    Op* opTestTwo = new Op(-10.12);
    Base* test = new Sub(opTestOne, opTestTwo);
    EXPECT_DOUBLE_EQ(test->evaluate(), -0.12 - -10.12);
}

TEST(SubTest, SubEvaluateZero) {
     Op* opTestOne = new Op(5.1);
     Op* opTestTwo = new Op(0);
     Base* test = new Sub(opTestOne, opTestTwo);             
     EXPECT_DOUBLE_EQ(test->evaluate(), 5.1 - 0);
}

TEST(SubTest, SubStringifyZeroandPos) {
     Op* opTestOne = new Op(0);
     Op* opTestTwo = new Op(8.9);
     Base* test = new Sub(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(0 - 8.9)");
}

TEST(SubTest, SubStringifyNeg) {
     Op* opTestOne = new Op(-14.8);
     Op* opTestTwo = new Op(1.7);
     Base* test = new Sub(opTestOne, opTestTwo);
     EXPECT_TRUE(test->stringify() == "(-14.8 - 1.7)");
}
                  		    			    	    	    	   
#endif //__SUB_TEST_HPP__
