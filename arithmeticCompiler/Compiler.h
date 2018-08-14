//
//  Compiler.h
//  arithmeticComiler
//

#include <stdio.h>
#include <iostream>
#include <vector>

#ifndef Compiler_h
#define Compiler_h

enum TokenType { NUM, OP};

//std::string operators[6] = {"+", "-", "*", "\\", "(", ")"};
//data structure is string array because I may add binary operator like : ++ -- 

//for (int i = 0; i < 4; i++)
//cout << colour[i] << "\n";

struct Token
{
	std::string code;
	TokenType type;	
};

struct ValInfoBlock
{
//    std::string token;
//    double value;
};

struct OpInfoBlock
{
    
};

class Compiler
{
    std::vector<OpInfoBlock> OpStack;
    std::vector<ValInfoBlock> ValStack;
public:
    void parse(const std::string &_code);
    double getResult();
};

#endif /* Compiler_h */
