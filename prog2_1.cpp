#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int tokenize(string in);
string simplify(string tokens[], int c);
bool isInt(string s);
bool isQuit(int c);
bool checkOutput(string o, int c);

const int CONSTRAINT = 65;
string tokenized[16];

int main(int argc, char **argv) {

    string input;
    string output;
    int count;
    bool check;
    bool go = true;

    cout << "Assignment #2-1, Alexander Pearson-Goulart, pearsongoulart@gmail.com\n";

    if(argc != 2) {
        cout << "ERROR! Program accepts 1 command line argument.\n";
        exit(0);
    }

    if(!isInt(argv[1])) {
        cout << "ERROR! Expected integer argument.\n";
        exit(0);
    }

    int numArgs;
    int argCount = 0;

    stringstream ss(argv[1]);
    ss >> numArgs;
    
    cout << "> ";

    while(argCount < numArgs) {

        getline(cin, input);

        while(input.length() > CONSTRAINT) {
            cout << "ERROR! Input string too long.\n> ";
            getline(cin, input);
            argCount++;
        }

        count = tokenize(input);

        while(count > 2) {
            cout << "ERROR! Incorrect number of tokens found.\n> ";
            getline(cin, input);
            argCount++;
            count = tokenize(input);
        }

        if(isQuit(count)) {
            return 0;
        }

        output = simplify(tokenized, count);
        check = checkOutput(output, count);

        while(!check) {
            getline(cin, input);
            argCount++;
            count = tokenize(input);

            while(count > 2) {
                cout << "ERROR! Incorrect number of tokens found.\n> ";
                getline(cin, input);
                argCount++;
                count = tokenize(input);
            }

            if(isQuit(count)) {
                return 0;
            }

            output = simplify(tokenized, count);
            check = checkOutput(output, count);
        }

        cout << output;

        cout << "> ";
        argCount++;

        /*
        for(int i = 0; i < count; i++) {
            cout << "=" << tokenized[i] << "=" << endl;  
        } 
        */

    }

}


int tokenize(string in) {
    int count = 0;
    string token;

    stringstream s(in);
    while(s >> token) {
        tokenized[count] = token;
        count++;
    } 

    return count;
}

string simplify(string tokens[], int c) {
    int index = 0;
    string out;

    while(index < c) {
        if(isInt(tokens[index])) {
            out.append("INT ");
            index++;
        }
        else {
            out.append("STR ");
            index++;
        }
    }

    out.append("\n");

    return out;
}

bool isInt(string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

bool isQuit(int c) {
    if(c == 1) {
        string isit = tokenized[0];
        transform(isit.begin(), isit.end(), isit.begin(), ::tolower);

        if(isit.compare("quit") == 0) {
            return true;
        }
    } 

    return false;
}

bool checkOutput(string o, int c) {
    if(o.compare("STR INT \n") == 0) {
        return true;
    }
    else if(o.compare("STR \n") == 0) {
        return true;
    }
    else if(c == 2) {
        cout << "ERROR! Expected STR INT.\n> ";
        return false;
    }
    else {
        cout << "ERROR! Expected STR.\n> ";
        return false;
    }
}

