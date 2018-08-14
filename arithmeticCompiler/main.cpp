//
//  main.cpp
//  arithmeticComiler
//
//  Created by wingrove on 2018/8/7.

#include <iostream>
#include "Compiler.h"

double clac(const std::string &_code)
{
    Compiler cpl;
    cpl.parse(_code);
    return cpl.getResult();
}

int main(int argc, const char * argv[])
{
    std::string code_1("(13+(3+32))*59/23+6.2/2");
    clac(code_1);
    return 0;
}
