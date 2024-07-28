#include "rpn.h"
#include <iostream>

int main()
{
    char exp2[100] = "1+2*3-4/5^2";
    char rpn2[100] = "";
    double result = evalute(exp2, rpn2);
    std::cout << exp2 << std::endl;
    std::cout << rpn2 << std::endl;
    std::cout << result << std::endl;
}