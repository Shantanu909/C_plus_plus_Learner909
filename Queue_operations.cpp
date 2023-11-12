#include <iostream>
using namespace std;

class Queue {
private:
    static const int processes = 6;
    int data[processes];
    int front;
    int rear;
    int arrv_t[processes] = {0, 1, 5, 6, 10, 15};
    int need_t[processes] = {5, 2, 7, 1, 3, 1};
    int ende_t[processes] = {0, 0, 0, 0, 0, 0};

public:
    Queue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int value) {
        data[rear] = value;
        rear = (rear + 1) % processes;
    }

    int dequeue() {
        if (!isEmpty()) {
            int dequeuedValue = data[front];
            front = (front + 1) % processes;
            return dequeuedValue;
        } else {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Processes:" << endl;
        int index = front;
        while (index != rear) {
            int start_t = (index == 0) ? arrv_t[index] : ende_t[index - 1];
            int end_t = start_t + need_t[index];
            int wait_t = start_t - arrv_t[index];
            
            cout << "Process " << index + 1 << " | " << start_t << " | " << end_t << " | " << arrv_t[index] << " | " << wait_t << endl;

            ende_t[index] = end_t;
            index = (index + 1) % processes;
        }
    }
};

int main() {
    Queue queue;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue status" << endl;
        cout << "4. Exit" << endl;

        int option;
        cin >> option;

        switch (option) {
            case 1:
                int value;
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
//            case 2:
//                int dequeuedValue = queue.dequeue();
//                cout << "Dequeued value: " << dequeuedValue << endl;
//                break;
            case 3:
                queue.display();
                break;
            case 4:
                return 0;
            default:
                cerr << "Invalid option. Please choose a valid option." << endl;
                break;
        }
    }
}
