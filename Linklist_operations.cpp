#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Element " << value << " inserted." << endl;
    }

    void find(int value) {
        Node* current = head;
        int counter = 0;
        while (current) {
            if (current->data == value) {
                cout << "Your number: " << value;
                cout << " is present at index no: " << counter << "\n";
                return;
            }
            counter++;
            current = current->next;
        }
        cout << "Element not found in the list!" << endl;
    }

    void remove(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << value << " deleted." << endl;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Element " << value << " deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Element " << value << " not found." << endl;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void ReverseTheLinkedList() {
        if (!head) {
            cout << "List is empty. Cannot reverse." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed." << endl;
    }

    void count_nodes() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        int counter = 0;
        while (current) {
            counter++;
            current = current->next;
        }
        cout << "There are: " << counter << " nodes in the list." << endl;
    }

    LinkedList copyList() {
        LinkedList newList;
        Node* current = head;

        while (current != nullptr) {
            newList.insert(current->data);
            current = current->next;
        }

        cout << "List copied." << endl;
        return newList;
    }

    void concatenateLists(LinkedList& list2) {
        if (head == nullptr) {
            head = list2.head;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = list2.head;
        }

        cout << "Lists concatenated." << endl;
    }

    void splitList(LinkedList& list1, LinkedList& list2) {
        if (head == nullptr) {
            cout << "List is empty. Cannot split." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        list1.head = head;
        list2.head = slow->next;
        slow->next = nullptr;

        cout << "List split." << endl;
    }
};

int main() {
    LinkedList list;

    int choice = 0;
    double data = 0.0;
    int temp_size;
    int temp_s;

    cout << "Please enter the length of your linked list\n";
    cin >> temp_size;

    cout << "Please enter the list elements one after another\n";
    for (int i = 0; i < temp_size; i++) {
        cin >> temp_s;
        list.insert(temp_s);
    }

    int df = 1;
    while (df > 0) {
        cout << "Linked List \n";
        cout << "Enter 1 for Insert\n";
        cout << "Enter 2 for Find\n";
        cout << "Enter 3 for Delete\n";
        cout << "Enter 4 for Display List\n";
        cout << "Enter 5 for Reversing the list\n";
        cout << "Enter 6 for Counting the nodes in the list\n";
        cout << "Enter 7 for Copying the list\n";
        cout << "Enter 8 for Concatenating the lists\n";
        cout << "Enter 9 for Splitting the list\n";
        cin >> choice;

        switch (choice) {
            case 1:{
				
                cout << "Enter data to create a new node\n";
                cin >> data;
                list.insert(data);
                break;}
            case 2:{
                cout << "Enter data to find from the list\n";
                cin >> data;
                list.find(data);
                break;}
            case 3:{
                cout << "Enter data to be deleted\n";
                cin >> data;
                list.remove(data);
                break;}
            case 4:{
                list.display();
                break;}
            case 5:{
                list.ReverseTheLinkedList();
                break;}
            case 6:{
                list.count_nodes();
                break;}
            case 7:{
                list.copyList();
                break;}
            case 8:{
                LinkedList list2;
                cout << "Enter the elements for the second list\n";
                for (int i = 0; i < temp_size; i++) {
                    cin >> temp_s;
                    list2.insert(temp_s);
                }
                list.concatenateLists(list2);
                break;}
            case 9:    	{
				
                LinkedList list1Split, list2Split;
                list.splitList(list1Split, list2Split);
                cout << "First List after split: ";
                list1Split.display();
                cout << "Second List after split: ";
                list2Split.display();
                break;
            }
            default:{
                cout << "Invalid choice";
            break;
			}
			}
        cout << "Press 0 for exit, any other number to rerun.";
        int x;
        cin >> x;
        if (x == 0) {
            df = 0;
        }
    }
    return 0;
}

