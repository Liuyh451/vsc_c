// Stack.cpp

#include "Stack.h"
#include <iostream>

void initialize(Stack& stack) {
    stack.top = -1;
}

bool isEmpty(const Stack& stack) {
    return stack.top == -1;
}

bool isFull(const Stack& stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack& stack, int value) {
    if (isFull(stack)) {
        std::cout << "Stack overflow\n";
        return;
    }
    stack.data[++stack.top] = value;
}

int pop(Stack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack underflow\n";
        
    }
    return stack.data[stack.top--];
}

int top(const Stack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack is empty\n";
        exit(EXIT_FAILURE);
    }
    return stack.data[stack.top];
}
