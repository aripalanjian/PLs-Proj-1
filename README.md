# PLs-Proj-1
Recursive-Descent Parser

Contributor(s): Ari Palanjian

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
