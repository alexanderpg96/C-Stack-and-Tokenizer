#include "Tokenizer.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

string tokenized[16];
string tokens[2];

bool Tokenizer::isInt(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

int Tokenizer::tokenize(string in) {
    int c = 0;
    string token;

    stringstream s(in);
    while(s >> token) {
        tokenized[c] = token;
        c++;
    } 

    return c;
}

bool Tokenizer::isQuit(int c) {
    if(c == 1) {
        string isit = tokenized[0];
        transform(isit.begin(), isit.end(), isit.begin(), ::tolower);

        if(isit.compare("quit") == 0) {
            return true;
        }
    } 

    return false;
}

void Tokenizer::simplify(int c) {
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

bool Tokenizer::checkOutput(int c) {
    if(c == 2) {
        if((tokens[0].compare("STR ") == 0) && (tokens[1].compare("INT ") == 0)) 
        {            
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

string* Tokenizer::GetTokens() {
    string input;
    int count;
    bool check;

    cout << "> ";

    getline(cin, input);

    count = tokenize(input);

    if(isQuit(count)) {
        exit(0);
    }

    if(count == 1) {
        tokenized[1] = "";
    }

    while(count > 2) {
        cout << "ERROR! Incorrect number of tokens found.\n> ";
        getline(cin, input);
        count = tokenize(input);
    }

    if(isQuit(count)) {
        exit(0);
    }

    simplify(count);

    check = checkOutput(count);

    while(!check) {
        getline(cin, input);

        count = tokenize(input);

        if(isQuit(count)) {
            exit(0);
        }

        if(count == 1) {
            tokenized[1] = "";
        }

        while(count > 2) {
            cout << "ERROR! Incorrect number of tokens found.\n> ";
            getline(cin, input);
            count = tokenize(input);
        }  

        if(isQuit(count)) {
            exit(0);
        }    

        simplify(count);
        check = checkOutput(count);
    }

    return tokenized;
}

