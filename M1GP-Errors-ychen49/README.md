# Errors
This project is riddled with errors. Please fix all the bugs!

## Setup
Use this Guided Project template to create a new repository (see [GitHub-with-CLion](https://github.com/uvmcs120s2022/GitHub-with-CLion) repo for directions).
**Your repository must be named with the convention: Errors-netid**, where netid is your UVM NetID username.

When you first put it into CLion, the Build and Run buttons will be grayed out and unclickable. This is intentional. You will need to start fixing bugs before these buttons can be used.

Remember to commit and push frequently.

## Errors
There are three types of errors:
1. **Compiler errors** prevent your program from running. These are typically CMake or syntax errors.
1. **Runtime errors** occur while the program is running and prevent an exit code of zero. Examples of this include a non-zero exit code and an infinite loop.
1. **Logic errors** are when your program runs to completion (with exit code zero) but does not behave the way you intended. The best way to catch logic errors is through extensive testing and/or the use of the debugger.

For this project, you have been given a very broken program and it is your job to fix it. For each error you fix, log it in the table below.

## Logging Errors
Every time you fix a bug, log it in the README file here:

| Type of error (compiler, runtime, logic) | File           | Description                                                                            | Fix                                                          |
|------------------------------------------|----------------|----------------------------------------------------------------------------------------|--------------------------------------------------------------|
| compiler                                 | CMakeLists.txt | "CMake Error at CMakeLists.txt:6 (add_executable): No SOURCES given to target: Errors" | Added the project name and .cpp files name to line 6         |
| compiler                                 | spie.h         | "error: 'ostream'/'istream' has not been declared"                                     | adding std prefix                                            |
| compiler                                 | spie.h         | "error: 'vector' does not name a type"                                                 | adding the data type in that vector                          |
| compiler                                 | main.cpp       | many class methods in header file receive multiple arguments                           | main.cpp includes the class header file instead of .cpp file |
| compiler                                 | main.cpp       | "warning: empty parentheses were disambiguated as a function declaration"              | remove the parentheses on line5                              |
| compiler                                 | main.cpp       | "error: request for member 'print_winning_numbers' in 'game'"                          | add parameter in the parentheses on line7                    |
| compiler                                 | main.cpp       | "error: case label ''s'' not within a switch statement"                                | fix syntax and add brace in switch statement                 |
| compiler                                 | main.cpp       | "error: case label ''i'' not within a switch statement"                                | fix the switch-case syntax                                   |
| compiler                                 | main.cpp       | "error: expected unqualified-id before 'if'"                                           | fix the braces                                               |
| compiler                                 | spie.cpp       | "warning: no return statement in function returning non-void"                          | add return statement on line 36                              |
| runtime                                  | spie.cpp       | using "or" instead of "and"                                                            | change or into and                                           |
| runtime                                  | spie.cpp       | wrong while syntax                                                                     | fix the syntax by separating them into pieces                |
| runtime                                  | spie.cpp       | program end with non-zero exit code when rolled dice matches                           | remove the erase() function to make simple replacement       |
| logic                                    | spie.cpp       | no numbers added when creating spie object                                             | add push_back() after the foor loop ends on line 26          |
| logic                                    | spie.cpp       | the output message is not complete with bad input                                      | change "if" statement into "while" statement at line 34      |





### Grading Rubric
- [ ] (2 pts) Fix at least one CMake compiler error (not including the one already given).
- [ ] (3 pts) Fix at least one other compiler error.
- [ ] (3 pts) Fix at least one runtime error.
- [ ] (3 pts) Fix at least one logic error.
- [ ] (5 pts) The README table is populated fully and correctly.
- [ ] (4 pts) Fix at least 15 errors total (note: errors you create do not count).
