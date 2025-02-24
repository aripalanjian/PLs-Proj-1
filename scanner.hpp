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
    void tokenize();

    std::pair<bool, int> isValidIden(const std::string, int currentPos);
    int isValidNum(const std::string, int currentPos); //Consider renaming function

public:
    Scanner(std::string file, bool debug);

    std::vector<std::string> getTokens();
};

#endif