#include "scanner.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>

Scanner::Scanner(std::string file, bool debug){
    this->file = file;
    this->debug = debug;
    readFile();
    tokenize();
}

void Scanner::readFile(){
    std::string line;
    std::fstream in(file);

    if (in.is_open()){
        while(getline(in, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            source.emplace_back(line);
        }

        if (debug) std::cout << "File contains " << source.size() << " lines\n";

        in.close();
    } else {
        std::cerr << "Error: " << errno << ", file unable to open or is not recognized";
    }
}

void Scanner::tokenize(){
    for (int i = 0; i < source.size(); i++){

        std::string line = source.at(i);
        if (debug) std::cout << line << "\n";

        char current;
        // char lookahead;
        if (line.at(0) == '~'){
            tokens.emplace_back("comment");
        } else if (line.compare("begin") == 0){
            tokens.emplace_back("beg");
        } else if (line.compare("end.") == 0){
            tokens.emplace_back("end");
            break;
        } else {
            bool isComment = false; 
            for (int j = 0; j < line.size(); j++){
                if(isComment) break;

                current = line.at(j);
                // lookahead = (j == line.size() - 1) ? '\n' : line.at(j+1);
                
                if (std::isalpha(current)){
                    auto isValid = isValidIden(line, j); // Will have to adapt for multiple assignments on one line
                    j = isValid.second;
                    if(isValid.first){
                        tokens.emplace_back("validIden");
                    } else {
                        tokens.emplace_back("invalidIden");
                    }
                } else if (std::isdigit(current)){
                    j = isValidNum(line, j);
                } else if (current == '~'){
                    isComment = true;
                    tokens.emplace_back("comment");
                } else if (current == '='){
                    tokens.emplace_back("assign");
                } else if (current == '('){
                    tokens.emplace_back("lParen");
                } else if (current == ')'){
                    tokens.emplace_back("rParen");
                } else if (current == '['){
                    tokens.emplace_back("lBracket");
                } else if (current == ']'){
                    tokens.emplace_back("rBracket");
                } else if (current == ';'){
                    tokens.emplace_back("terminator");
                } else if (current == '+'){
                    tokens.emplace_back("add");
                } else if (current == '-'){
                    tokens.emplace_back("subtract");
                } else if (current == '*'){
                    tokens.emplace_back("multiply");
                } else if (current == '/'){
                    tokens.emplace_back("divide");
                } else if (current == '%'){
                    tokens.emplace_back("modulo");
                }
            }
        }
        tokens.emplace_back("newline");
    }
}

std::pair<bool, int> Scanner::isValidIden(const std::string line, int currentPos) {
    int endIden = line.find('=') - 1;
    if (endIden < currentPos) {
        endIden = line.find(';') - 1;
    }
    // for (int i = currentPos; i < line.size(); i++){
    //     if (line.at(i) == '='){
    //         endIden = i - 1;
    //     }
    // }

    std::string identifier = line.substr(currentPos, endIden);
    
    if (debug) std::cout << "End of Identifier: " << endIden << ", " << identifier << '\n';
    
    bool isValid = true;
    int consecUnderScores = 0;
    for (int i = 0; i < identifier.size(); i++) {
        if (consecUnderScores > 1) {
            isValid = false;
            errorMsg = "Invalid Identifier";
        }

        if ( identifier.at(i) == '_') {
            consecUnderScores++;
            if (i == identifier.size() - 1 || i == 0){
                isValid = false;
                errorMsg = "Invalid Identifier";
            }
        }
    }

    if (isValid) symTable.insert({identifier, line.substr(endIden+1,line.find(';'))});

    return std::pair<bool, int>{isValid, endIden};
}

int Scanner::isValidNum(const std::string line, int currentPos){
    int i;
    for (i = currentPos; i < line.size(); i++) {
        if (!std::isdigit(line.at(i))){
            break;
        }
    }

    return i - 1;
}

std::vector<std::string> Scanner::getTokens (){
    return tokens;
}

/*
Tokens: comment, string literal, (valid/invalid)identifier, assignment operator, numerical literal, terminator , beg, end, lParen, rParen, lBracket, rBracket, arithmetic operator
*/