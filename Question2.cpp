#include "Question2.h"

bool Vector_Based_Stack::empty() const {
    return stack.empty();
}

void Vector_Based_Stack::push(int element) {
    stack.push_back(element);
}

void Vector_Based_Stack::pop() {
    stack.pop_back();
}

const int Vector_Based_Stack::top() const {
    if (!empty())
        return stack.back();
    else {
        cerr << "Stack is empty. No top element.\n";
        return -1;
    }
}

size_t Vector_Based_Stack::size() const {
    return stack.size();
}

float Vector_Based_Stack::findAverage() {
    int sum = 0;
    for (int value : stack)
        sum += value;  // Summing all the elements using a loop

    int average = sum / stack.size();

    return average;
}

void Vector_Based_Stack::printStack() {
    for (int value : stack)
        cout << value << " ";
}