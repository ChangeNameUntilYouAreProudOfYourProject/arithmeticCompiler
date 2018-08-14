//
//  Compiler.cpp
//  arithmeticComiler
//
//  Created by wingrove on 2018/8/7.
//  Copyright © 2018 wingrove. All rights reserved.
//

#include "Compiler.h"
#include <iostream>
#include <stack>

std::string operators[6] = {"+", "-", "*", "/", "(", ")"};

std::string matchFirstNum(const std::string &str)
{
    int len = 0;
    
    while(std::isdigit(str.at(len)) || str.at(len) == '.'){
        len++;
        if (len >= str.length()) {
            break;
        }
    }
    return str.substr(0,len);
}

std::string matchFirstOperator(const std::string &str)
{
    //designed for operator whose length > 1
    //bigString.compare(0, smallString.length(), smallString) == 0
    for (int i = 0 ; i < sizeof(operators)/sizeof(operators[0]); i++) {
        if (str.compare(0, operators[i].length(), operators[i]) == 0) {
            return operators[i];
        }
    }
    // this is not beautiful, modify it later
    std::cout << "syntax error in program" << std::endl;
    exit(0);
}

bool isOperator(const char c)
{
    //8.14 Question: is there a better way to get size of that array?
    for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++){
        if (c == operators[i].at(0)) {
            return true;
        }
    }
    return false;
}

Token parseNext(const std::string &str)
{
    /* parseNext() judge the first token
     * to see if it's NUM or OP return the token
     * */
    /*
     *8.13 I need to do some testing for the four functions above
     * */
    Token token;
    
    if(str.length() == 0){
        token.code = "\0";
    }else if(std::isdigit(str.at(0))){
        token.type = NUM;
        token.code = matchFirstNum(str);
    }else if(isOperator(str.at(0))){
        token.type = OP;
        token.code = matchFirstOperator(str);
    }
    
    return token;
}

void testOfFunctions(const std::string &s)
{
	int i;
    /*
     The code below is used for testing isOperator()
     */
//    for(i = 0; i < s.length(); i++){
//        std::cout << "character is : " << s.at(i) << std::endl;
//        std::cout << "if the char is operator :" << isOperator(s.at(i)) << std::endl;
//    }
    /*
     The code below is used for testing matchFirstOperator()
     */
//    for(i = 0; i < s.length(); i++){
//   	if( isOperator(s.at(i))){
//		std::cout << "string is: " << s.substr(i, s.size()) << std::endl;
//		std::cout << "match the first OP: " << matchFirstOperator(s.substr(i, s.size())) << std::endl;	
//	} 
//    }
    /*
     The code below is used for testing matchFirstNum()
     */
    for(i = 0; i < s.length(); i++){
        if( isdigit(s.at(i))){
            std::cout << "string is: " << s.substr(i, s.size()) << std::endl;
            std::cout << "match the first Number: " << matchFirstNum(s.substr(i, s.size())) << std::endl;
        }
    }

}

void Compiler::parse(const std::string &_code)
{
    //question: const std::string &_code, is the reason why we use const for _code is we want to keep an copy of _code?
    std::string str = _code;
    //_code is string & but str is string, why we can assign _code to str?
    //8.11 goal: built an tokenization scanner
    Token token;

    //testOfFunctions(_code);

    while((token = parseNext(str)).code != "\0")
    {
        std::cout << "str is " << str << std::endl;
        std::cout << "first token is " << token.code << std::endl;
    std::cout << "type is " << token.type << std::endl;
       str = str.substr(token.code.length(),str.length());
    }
    
    /**
    while((token = parseNext()) != EOF){
        parseNext() return an token
        if(token is NUM)
            push it to value stack
        if(token is OP)
    }
    
    **/
}

double Compiler::getResult()
{
    //8.11: I don't fully understand the use of getResult() function, because we do the calculation while operate the stack
    //double result;
    return 0;
}
