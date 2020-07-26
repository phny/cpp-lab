/*************************************************************************
        > File Name: test_string_util.cpp
        > Author:
        > Mail:
        > Created Time: 2020年07月01日 星期三 07时41分46秒
 ************************************************************************/

#include "src/string_util.h"
#include <gtest/gtest.h>
using namespace std;

TEST(Test_StringUtil, ToInt) { EXPECT_TRUE(StringUtil::ToInt("345") == 345); }
