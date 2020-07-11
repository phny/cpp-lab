/*************************************************************************
        > File Name: test_calc.cpp
        > Author:
        > Mail:
        > Created Time: 2020年07月01日 星期三 07时41分18秒
 ************************************************************************/

#include "src/calc.h"
#include <gtest/gtest.h>
using namespace std;

TEST(Test_Calc, Add) { EXPECT_TRUE(Calc::Add(3, 5) == 8); }
