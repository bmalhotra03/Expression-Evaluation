// Brij Malhotra
// hw4_5.cpp
// Purpose: Make a program that 1) Evaluates and calculates an expression provided by the user 
// 2) Finds the average of a window of integers 

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

// Class declaration

class DynamicQueue {
    
    private :
        struct QueueNode {
            int value;
            QueueNode * next;
        };

        QueueNode * front;
        QueueNode * rear;
        int numItems;
    
    public: 
        DynamicQueue();
        ~DynamicQueue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
        void average(int);
};

#endif 