#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

class Scanner{
    std::unordered_map<std::string, std::string> symTable;
    std::vector<std::string> source;
    std::vector<std::string> tokens;
    std::string file;
    std::string errorMsg;//Change this to flag numbers and have error handling function, change errorMsg to custErrno

    bool debug;

    void readFile();

    // After Reading Lexical Analysis
    int token;
    int nextToken;
    std::string lexeme;
    std::string lastIdent;
    std::vector<std::string> numValues;

    int lookup(char c);
    bool isValidNum(const std::string &);
    bool isValidIden(const std::string &);
    
    void tokenize2();
    
public:
    Scanner(std::string file, bool debug);

    std::vector<std::string> getTokens(){return tokens;}
    void printIdent();
};

#endif