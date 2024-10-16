// Brij Malhotra
// hw4_5.cpp
// Purpose: Make a program that 1) Evaluates and calculates an expression provided by the user 
// 2) Finds the average of a window of integers 

#include "Queue.h"
#include <iostream>

using namespace std;

// Class definition

DynamicQueue::DynamicQueue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

DynamicQueue::~DynamicQueue() {
    QueueNode * curr = front;
    QueueNode * next = curr->next;

    while (curr!=nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    front = nullptr;
    rear = nullptr;
}

void DynamicQueue::enqueue(int num) {
    QueueNode * newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++;
}

int DynamicQueue::dequeue() {
    if (isEmpty()) {
        cout << " The queue is empty.\n";
        return -1;
    } else {
        int value  = front->value;
        QueueNode * temp = front; 
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        numItems--;
        return value;
    }
}

bool DynamicQueue::isEmpty() const { return numItems == 0; }

void DynamicQueue::average(int num) { // This function gets the average of the window size N
    QueueNode * curr = front;
    QueueNode * window = front;

    if (!front) {
        cout << " The queue is empty, therefore no average values are available.";
    } else {
        cout << "    The average in each window of size " << num << " is: [ ";

        while (curr!=nullptr) {
            int avg = 0;

            curr = window; // The window pointer points to the one which is ahead so that later on the current can point to
            window = curr->next; // it and continue the iteration of averaging for the next window
            
            for (int i = 0; i < num; i++) {
                avg += curr->value;
                curr = curr->next;
            }

            avg = avg / num;

            cout << avg << " ";
       }
       cout << "]";
    }
}