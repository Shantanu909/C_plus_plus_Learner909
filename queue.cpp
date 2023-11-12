#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 100; // Maximum queue size
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(0), rear(0) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Enqueue (add) an element to the rear of the queue
    void enqueue(int value) {
        if (!isFull()) {
            data[rear] = value;
            rear = (rear + 1) % MAX_SIZE;
        } else {
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
        }
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        if (!isEmpty()) {
            int dequeuedValue = data[front];
            front = (front + 1) % MAX_SIZE;
            return dequeuedValue;
        } else {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        int index = front;
        while (index != rear) {
            std::cout << data[index] << " ";
            index = (index + 1) % MAX_SIZE;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue queue;

    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display Queue" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                int value;
                std::cout << "Enter a value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                if (!queue.isEmpty()) {
                    int dequeuedValue = queue.dequeue();
                    std::cout << "Dequeued value: " << dequeuedValue << std::endl;
                }
                break;
            case 3:
                queue.display();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cerr << "Invalid option. Please choose a valid option." << std::endl;
                break;
        }
    }
}
