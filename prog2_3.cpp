#include "Stack.hpp"
#include "Tokenizer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int toInteger(string s);
bool isInt(string s);
string* GetTokens();

string * t;
string pushTok[3];

int main(int argc, char **argv) {

    Stack s;

    cout << "Assignment #2-3, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n";

    if(argc != 2) {
        cout << "ERROR! Program accepts 1 command line argument.\n";
        return 0;
    }

    if(!isInt(argv[1])) {
        cout << "ERROR! Expected integer argument.\n";
        return 0;
    }

    int numArgs;
    int argCount = 0;

    stringstream ss(argv[1]);
    ss >> numArgs;
    
    while(argCount < numArgs) {

        cout << "> ";

        t = GetTokens();

        //Put in Tokenizer
        //while((to[0].length() + tokens[1].length()) > CONSTRAINT) {
          //  cout << "ERROR! Input string too long.\n> ";
            //tokens = Tokenizer::GetTokens();
        //}

        if(pushTok[1].length() == 0) {
            if(t[0].compare("pop") == 0) {          
                s.Pop();
            }
        }
        else {
            if((t[0].compare("push") == 0) && isInt(t[1])) {
                s.Push(toInteger(t[1]));
            }
        }

        argCount++;

    }

    s.Print();
}

int toInteger(string s) {
    int numb;
    istringstream ( s ) >> numb;
    return numb;
}
