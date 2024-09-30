#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Vector_Based_Stack {
private:
    vector<int> stack;  // Vector to store the elements of the stack
public:
    // Check if the stack is empty or not
    bool empty() const;

    // Insert elements to the top of the stack
    void push(int element);

    // Remove element from the top of the stack
    void pop();

    // Return the top element of the stack
    const int top() const;

    // Return the size of the stack
    size_t size() const;

    // Find average value of the stack elements.
    float findAverage();

    // Print the stack elements
    void printStack();
};