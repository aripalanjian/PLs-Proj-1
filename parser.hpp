#ifndef PARSER_HPP
#define PARSER_HPP

#include "scanner.hpp"
// #include <stack>

class Parser{
    std::vector<std::string> tokens;
    std::string errorMsg;
    bool debug;

    bool isValid();

public:
    Parser(bool debug);

    void setTokens(std::vector<std::string> const);
    void parse();
};

#endif
