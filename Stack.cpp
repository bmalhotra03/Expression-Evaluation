// Brij Malhotra
// hw4_5.cpp
// Purpose: Make a program that 1) Evaluates and calculates an expression provided by the user 
// 2) Finds the average of a window of integers 

#include "Stack.h"
#include <iostream>

using namespace std;

// Class definition

DynamicIntStack::~DynamicIntStack() {
    StackNode * curr = top;
    StackNode * next = nullptr;

    while (curr!=nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    top = nullptr;
}

void DynamicIntStack::push(int num) {
    StackNode * newNode = new StackNode;
    newNode->value = num;

    if (isEmpty()) {
        top = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

int DynamicIntStack::pop() {
    StackNode * temp = nullptr;

    if (isEmpty()) {
         cout << " tHE STACK IS EMPTY.\n";
         return -1;
    } else {
        int returnValue = top->value;
        temp = top->next;
        delete top;
        top = temp;
        return returnValue;
    }
}

bool DynamicIntStack::isEmpty() { return top == nullptr; }

int  DynamicIntStack::sum() { // This function adds all the numbers together from the string 
    int summation = 0;

    while (!isEmpty()) {
        summation += expressionVal();
    }
    return summation;
}

int DynamicIntStack::expressionVal() { // This function makes sure that numbers are only separated by + and - signs so that
    string temp = "";                  // numbers are not separated and making 50 seem like 5 and 0.
    int num = 0;
    bool negative = false;

    if (top->value != '+' && top->value != '-') {
            temp = pop();
    } else if (top->value == '-'){      // The entire if else conditional statements handles the cases of the operators being used
        pop();                          // When + or - is used, we pop it and store it in temp, if not, we just move on
        temp = pop();
        negative = true;
    } else if (top->value == '+') {
        pop();
        temp = pop();
    }

    while (!isEmpty() && top->value != '-' && top->value != '+') {   // We add all the parts of expression together
        temp += pop();
    }

    if (!negative) {
        num = stoi(temp);
    } else {
        num = stoi(temp) * -1;
    }

    return num;
}
