#include <iostream>

// Define a singly-linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    // Print the linked list
    std::cout << "Linked List: ";
    printList(head);

    return 0;
}
