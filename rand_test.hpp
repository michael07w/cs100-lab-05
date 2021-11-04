#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include <sstream>
#include "gtest/gtest.h"
#include "rand.hpp"

TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
    // test that Rand returns double less than 100
    EXPECT_TRUE(test->evaluate() <= 100);
}

TEST(RandTest, RandStringify) {
    Rand* test = new Rand();
    // store string value
    std::ostringstream sstream;
    sstream << test->evaluate();

    EXPECT_EQ(test->stringify(), sstream.str());
}

#endif //__RAND_TEST_HPP__
