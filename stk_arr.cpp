#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum stack size
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            std::cerr << "Stack is full." << std::endl;
            return; // You can choose a different way to handle this error.
        }
        arr[++top] = value;
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        return arr[top--];
    }

    // Peek at the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    if (stack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
