/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月01日 星期三 07时39分08秒
 ************************************************************************/

# include <iostream>
# include "calc.h"
# include "string_util.h"
int main()
{
    std::cout<<"3+5="<<Calc::Add(3, 5)<<std::endl;
    std::cout<<"ToInt(345)="<<StringUtil::ToInt("345")<<std::endl;
    return 0;
}
