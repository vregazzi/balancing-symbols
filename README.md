# Balancing Symbols
This project implements a stack class that stores opening symbols, `{ [ ( <`, as they occur. When encountering closing symbols, `} ] ) >`, it checks if the top of the stack has a corresponding opening symbol for validity, failing if invalid. If the end of the string is reached and the stack is empty, the string passes.
