#include "Tokenizer.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isInteger(string s);
string* GetTokens();

const int CONSTRAINT = 65;
string * t;

int main(int argc, char **argv) {

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

        cout << "> ";

        t = GetTokens();

        // Change to go into tokenizer
        //while((tokens[0].length() + tokens[1].length()) > CONSTRAINT) {
          //  cout << "ERROR! Input string too long.\n> ";
            //tokens = GetTokens();
        //}
    

        if(t[1].length() == 0) {
            cout << t[0];
        }
        else {
            cout << t[0] << t[1];
        }

        cout << "\n";
        argCount++;

    }
}

bool isInteger(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}


