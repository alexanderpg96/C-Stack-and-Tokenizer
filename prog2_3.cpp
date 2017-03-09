#include "Stack.hpp"
#include "Tokenizer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

bool Tokenizer::isInt(string s);
int toInt(string s);
void simplify();
bool checkOutput(int c);
string* Tokenizer::GetTokens();

const int CONSTRAINT = 65;
string * tokens;
string pushTok[3];

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

        tokens = Tokenizer::GetTokens();

        //Put in Tokenizer
        while((tokens[0].length() + tokens[1].length()) > CONSTRAINT) {
            cout << "ERROR! Input string too long.\n> ";
            tokens = Tokenizer::GetTokens();
        }

        simplify();

        if(tokens[1].length() == 0) {
            count = 1;
        }
        else {
            count = 2;
        }

        check = checkOutput(count);

        while(!check) {
            tokens = Tokenizer::GetTokens();
            if(pushTok[1].length() == 0) {
                count = 1;
            }
            else {
                count = 2;
            }

            simplify();
            check = checkOutput(count);

            if(argCount == numArgs) {
                exit(0);
            }
        }

        if(pushTok[1].length() == 0) {
            if(tokens[0].compare("pop") == 0) {          
                s.Pop();
            }
        }
        else {
            if((tokens[0].compare("push") == 0) && isInt(tokens[1])) {
                s.Push(toInt(tokens[1]));
            }
        }

        argCount++;

    }

    s.Print();
}

void simplify() {
    int index = 0;
    int c = 2;

    while(index < c) {
        if(Tokenizer::isInt(tokens[index])) {
           pushTok[index] = "INT ";
           index++; 
        }
        else if(tokens[index].length() == 0) {
            pushTok[index] = "";
        }
        else {
            pushTok[index] = "STR ";
            index++;
        }
    }
}

bool checkOutput(int c) {
    if(c == 2) {
        if((pushTok[0].compare("STR ") == 0) && (pushTok[1].compare("INT ") == 0)) {
            return true;
        }
        else {
            cout << "ERROR! Expected STR INT.\n> ";
            tokens[1] = "";
            return false;
        }
    }
    else if(c == 1) {
        if(pushTok[0].compare("STR ") == 0) {
            pushTok[1] = "";
            return true;
        }
        else {
            cout << "ERROR! Expected STR.\n> ";
            pushTok[1] = "";
            return false;
        }
    }
}

int toInt(string s) {
    int numb;
    istringstream ( s ) >> numb;
    return numb;
}
