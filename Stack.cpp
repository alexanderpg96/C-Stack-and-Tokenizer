#include "Stack.hpp"

#include <iostream>

using namespace std;

int size;
int data[100];

Stack::Stack() {
    size = 0;
}

void Stack::Push(int d) {
    data[size] = d;
    size++;
}

int Stack::Pop() {
    if(size == 0) {
        return -1;
    }

    int val = data[size-1];

    size--;
    return val;
    
}

void Stack::Print() {
    cout << "[ ";
    for(int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "]\n";
}
