# PLs-Proj-1
Recursive-Descent Parser

Contributor(s): Ari Palanjian

## Program Structure

### Scanner
    - Scanner()                      Defualt constructor
    - Scanner(string file, debug)    Constructor to initialize file and set debug flag
    - std::string next()             return the next token
    - std::string getCurrent()       returns the current token
    - std::string lookahead()        returns the token one past the current token as long as it is not eof
    - std::string getCurrentLexeme() returns the lexeme matching the current token
    - void setSymVal(key, val)       unused created for project 2
    - void printIdent()              prints all identies recoginized by scanner
    - void printTokens()             prints all tokens derived from source code
### Parser
    - Parser(debug, string &file)    Constructor to set debug flag and store the source code file name
    - void parse()                   Initalizes the recursive descent to validate successful source code

## Usage
- From the command line run the following commands:

    ```make```
    
    ```make run```

## Error Messages
- The error messages follow the template from the rubric 
       
        ```Line <integer> contains error <errormsg> (missing ']', missing ')', expected assignment operator, expected operator, etc)```

- The error messages are derived from parsing the token stream and explain what the parser expected and the token that was actually recieved.

- Examples:

    ```Line 2 contains error expected 'identifier', found inval_ident.```

    ```Line 6 contains error expected '=', found lParen.```

    ```Line 4 contains error expected ')' found term_op```

    ```Line 4 contains error Unexpected token: ident "began".```
