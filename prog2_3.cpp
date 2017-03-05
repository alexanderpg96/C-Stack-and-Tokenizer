#include "Stack.hpp"
#include "Tokenizer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

bool isInt(string s);
void simplify(int c);
bool checkOutput(int c);
string* GetTokens();

const int CONSTRAINT = 65;
string * tokens;
string pushTok[16];

int main(int argc, char **argv) {

    bool check;
    Stack s;

    int count;

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

        tokens = GetTokens();
        pushTok = tokens;

        while((tokens[0].length() + tokens[1].length()) > CONSTRAINT) {
            cout << "ERROR! Input string too long.\n> ";
            tokens = GetTokens();
            pushTok = tokens;
            argCount++;
        }
    
        if(tokens[1].length() == 0) {
            count = 1;
        }
        else {
            count = 2;
        }

        simplify(count);

        check = checkOutput(count);

        while(!check) {
            tokens = GetTokens();
            pushTok = tokens;
            if(tokens[1].length() == 0) {
                count = 1;
            }
            else {
                count = 2;
            }

            simplify(count);
            check = checkOutput(count);
            argCount++;
        }

        if(tokens[1].length() == 0) {
            if(pushTok[0].compare("pop") == 0) {            
                s.Pop();
            }
        }
        else {
            if((pushTok[0].compare("push") == 0) && isInt(pushTok[1])) {
                s.Push(atoi(pushTok[1].c_str()));
            }
        }

        argCount++;

    }

    s.Print();
}

void simplify(int c) {
    int index = 0;

    while(index < c) {
        if(isInt(tokens[index])) {
           tokens[index] = "INT ";
           index++; 
        }
        else {
            tokens[index] = "STR ";
            index++;
        }
    }
}

bool checkOutput(int c) {
    if(c == 2) {
        if((tokens[0].compare("STR ") == 0) && (tokens[1].compare("INT ") == 0)) {
            return true;
        }
        else {
            cout << "ERROR! Expected STR INT.\n> ";
            tokens[1] = "";
            return false;
        }
    }
    else if(c == 1) {
        if(tokens[0].compare("STR ") == 0) {
            tokens[1] = "";
            return true;
        }
        else {
            cout << "ERROR! Expected STR.\n> ";
            tokens[1] = "";
            return false;
        }
    }
}
