Assignment 2
============

This assignment is a collection of C++ programs that implement two classes (Tokenizer and Stack) in order to build off of the previous Assignment 1.

Stack.cpp
---------

C++ class that builds a simple stack that can push, pop, and print the items within the stack.

Stack.hpp
---------

The header file for the Stack class. Implemented in Stack.cpp.

Tokenizer.cpp
-------------

C++ class that takes user input from STDIN and tokenizes it space delimited into a size 2 string array and returns the array. If there is only one token, the second item in the array is "". Only returns proper user input.

Tokenizer.hpp
-------------

The header for for the Tokenizer class. Implemented in Tokenizer.cpp

prog2_1.cpp
-----------

This program acts much like prog1_5 in Assignment 1. It takes in user input (no more than 65 characters) and checks the number and types of arguments (only 1 integer argument). The program only prints out STR INT or STR if the user input was tokenized into a string and int or just a string. Program terminated on "quit"

prog2_2.cpp
-----------

This program does the same thing as prog2_1 but it implements the Tokenizer class in order to perform its task.

prog2_3.cpp
-----------

This program builds on prog2_2, in that it utilizes the Tokenizer class in order to get tokenized user input. However, if user input is a STR INT or STR, it checks if the user typed "push *int*" or "pop". If it is "push *int*" the int is pushed onto the stack created by the Stack.cpp class, and if it is "pop" the last item in the stack is popped (if the stack is not empty). The program ends by printing the items within the stack.