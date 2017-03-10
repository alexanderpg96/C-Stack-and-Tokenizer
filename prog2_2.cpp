#include "Tokenizer.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

bool isInteger(string s);
string* GetTokens();

const int CONSTRAINT = 65;
string * t;
string * toks;

int main(int argc, char **argv) {

    Tokenizer tok;

    cout << "Assignment #2-2, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n";

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
            cout << "STR ";
        }
        else {
            cout << "STR " << "INT ";
        }

        cout << "\n";
        argCount++;

    }
}

bool isInteger(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}


