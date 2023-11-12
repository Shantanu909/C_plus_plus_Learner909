#include <iostream>
using namespace std;

class CircQueue {
private:
    int front, rear;
    int size;
    int* queue;

public:
    CircQueue(int size) {
        this->size = size;
        front = -1;
        rear = -1;
        queue = new int[size];
    }

    bool is_empty() {
        return front == -1 && rear == -1;
    }

    bool is_full() {
        return (rear + 1) % size == front;
    }

    void enqueue(int item) {
        if (is_full()) {
            cout << "Queue is full." << endl;
        } else {
            if (is_empty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            queue[rear] = item;
            cout << item << " enqueued to the queue." << endl;
        }
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
        } else {
            int item = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            cout << item << " dequeued from the queue." << endl;
        }
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }

    ~CircQueue() {
        delete[] queue;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircQueue cq(size);

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int item;
                cout << "Enter the item to enqueue: ";
                cin >> item;
                cq.enqueue(item);
                break;
            }
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
