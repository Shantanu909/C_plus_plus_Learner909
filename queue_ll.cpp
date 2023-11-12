#include <iostream>

// Define a singly-linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue (add) an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return dequeuedValue;
    }

    // Peek at the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << stdendl;
            return -1; // You can choose a different way to handle this error.
        }
        return front->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.peek() << std::endl;

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    if (queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
