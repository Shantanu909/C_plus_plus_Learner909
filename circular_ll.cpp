#include <iostream>

// Define a circular doubly-linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Function to print the circular doubly-linked list in a forward direction
void printForward(Node* head) {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Function to print the circular doubly-linked list in a backward direction
void printBackward(Node* head) {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    do {
        current = current->prev;
        std::cout << current->data << " ";
    } while (current != head);
    std::cout << std::endl;
}

int main() {
    // Create a sample circular doubly-linked list with three nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Connect the nodes in a circular manner
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = head;
    head->prev = third;

    // Print the circular doubly-linked list in both directions
    std::cout << "Circular Doubly-Linked List Forward: ";
    printForward(head);

    std::cout << "Circular Doubly-Linked List Backward: ";
    printBackward(head);

    return 0;
}
