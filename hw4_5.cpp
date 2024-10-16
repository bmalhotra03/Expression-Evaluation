// Brij Malhotra
// hw4_5.cpp
// Purpose: Make a program that 1) Evaluates and calculates an expression provided by the user 
// 2) Finds the average of a window of integers 

#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <fstream>

using namespace std; 

void calculate(string, DynamicIntStack &);

int main(int argc, char * argv[]) {
    
    DynamicIntStack eval;
    DynamicQueue queue;

    cout << endl << endl;
    
    cout << "****Showcasing the first task****" << endl; 
    string expression = "";

    while (expression != "#") {
        cout << "    Type the expression (type # to quit): ";
        getline(cin,expression);
        calculate(expression, eval);
    }

    cout << endl << endl; 

    cout << "****Showcasing the second task****" << endl;

    ifstream inputFile; 
    int num; 

    inputFile.open(argv[1]);
    
    if (inputFile) {
        while (inputFile >> num) {
            queue.enqueue(num);
        } 
        
        queue.average(stoi(argv[2]));
    } else {
        cout << " Error reading file." << endl;
        inputFile.close();
    }

    cout << endl << endl;
}

void calculate(string expression, DynamicIntStack & stack) {
    if (expression != "#") {
        for (int i = (expression.length() -1); i >= 0; i--) {
            stack.push(expression[i]);
        }

        int total = stack.sum();
        cout << "    The value of this expression is " << total << "." << endl << endl;
    }
}