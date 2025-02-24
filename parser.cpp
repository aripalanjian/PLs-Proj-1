#include "parser.hpp"
#include <iostream>

// public
Parser::Parser(bool debug){
    this->debug = debug;
}

void Parser::setTokens(std::vector<std::string> const tokens){
    this->tokens = tokens;
}

void Parser::parse(){
    std::cout << "Tokens: ";
    for (std::string token : tokens){
        std::cout << token << " ";
    }
    std::cout << '\n';
}