#include <iostream>

// Define a singly-linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Peek at the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        return top->data;
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
