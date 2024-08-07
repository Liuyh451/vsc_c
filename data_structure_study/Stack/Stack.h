// Stack.h

#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 20

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(Stack& stack);
bool isEmpty(const Stack& stack);
bool isFull(const Stack& stack);
void push(Stack& stack, int value);
int pop(Stack& stack);
int top(const Stack& stack);

#endif // STACK_H
