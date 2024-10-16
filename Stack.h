// Brij Malhotra
// hw4_5.cpp
// Purpose: Make a program that 1) Evaluates and calculates an expression provided by the user 
// 2) Finds the average of a window of integers 

#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

// Class declaration

class DynamicIntStack
{
    private: 
        struct StackNode {
            int value;
            StackNode * next;
        };

        StackNode * top;

    public: 
        DynamicIntStack() { top = nullptr;}
        ~DynamicIntStack();
        void push(int);
        int pop();
        bool isEmpty();
        int sum();
        int expressionVal();
};

#endif
