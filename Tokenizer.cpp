#include "Tokenizer.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

string tokenized[16];

bool Tokenizer::isInt(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

int Tokenizer::tokenize(string in) {
    int count = 0;
    string token;

    stringstream s(in);
    while(s >> token) {
        tokenized[count] = token;
        count++;
    } 

    return count;
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

string* Tokenizer::GetTokens() {
    string input;
    int count;

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
    
        if(isQuit(count)) {
            exit(0);
        }

        if(isQuit(count)) {
            exit(0);
        }
    }

    return tokenized;
}

