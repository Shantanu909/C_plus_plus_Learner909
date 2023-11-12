#include <iostream>

// Define a doubly-linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Function to print the doubly-linked list forward
void printForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to print the doubly-linked list backward
void printBackward(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample doubly-linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Connect the nodes forward and backward
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print the doubly-linked list in both directions
    std::cout << "Doubly-Linked List Forward: ";
    printForward(head);

    std::cout << "Doubly-Linked List Backward: ";
    printBackward(third);

    return 0;
}
