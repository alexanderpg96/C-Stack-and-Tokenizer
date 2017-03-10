#include "Stack.hpp"
#include "Tokenizer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int toInteger(string s);
bool isInteger(string s);
//string* GetTokens();

string * t;
string pushTok[3];

int main(int argc, char **argv) {

    Stack s;
    Tokenizer tok;

    cout << "Assignment #2-3, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n";

    if(argc != 2) {
        cout << "ERROR! Program accepts 1 command line argument.\n";
        return 0;
    }

    if(!isInteger(argv[1])) {
        cout << "ERROR! Expected integer argument.\n";
        return 0;
    }

    int numArgs;
    int argCount = 0;

    stringstream ss(argv[1]);
    ss >> numArgs;
    
    while(argCount < numArgs) {

        t = tok.GetTokens();

        if(t[1].length() == 0) {

            string isit = t[0];

            transform(isit.begin(), isit.end(), isit.begin(), ::tolower);

            if(isit.compare("quit") == 0) {
                exit(0);
            }

        }

        if(t[1].length() == 0) {
            if(t[0].compare("pop") == 0) {          
                s.Pop();
            }
        }
        else {
            if((t[0].compare("push") == 0) && isInteger(t[1])) {
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

bool isInteger(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}
