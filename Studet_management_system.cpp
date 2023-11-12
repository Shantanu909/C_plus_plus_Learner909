/**6). Create a menu driven program to perform operation on students:
a) add new student
b) delete student based on enrollment no.
c) display all students details, like name, enrollment no, age, etc.
d) sort all students based on age.
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int enrollmentNo;
    int age;

    Student(string n, int en, int a) : name(n), enrollmentNo(en), age(a) {}
};

class Node {
public:
    Student* data;
    Node* next;
    Node(Student* student) : data(student), next(NULL) {}
};

class List {
private:
    Node* head;

public:
    List() : head(NULL) {}

    void insert(Student* student) {
        Node* newNode = new Node(student);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Student " << student->name << " with enrollment number " << student->enrollmentNo << " inserted." << endl;
    }

    bool find(int enrollmentNo) {
        Node* current = head;
        while (current) {
            if (current->data->enrollmentNo == enrollmentNo) {
                cout << "Student found: Name: " << current->data->name << ", Enrollment No: " << current->data->enrollmentNo << ", Age: " << current->data->age << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Student with enrollment number " << enrollmentNo << " not found." << endl;
        return false;
    }

    void remove(int enrollmentNo) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->data->enrollmentNo == enrollmentNo) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student with enrollment number " << enrollmentNo << " deleted." << endl;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data->enrollmentNo == enrollmentNo) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Student with enrollment number " << enrollmentNo << " deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Student with enrollment number " << enrollmentNo << " not found." << endl;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << "Name: " << current->data->name << ", Enrollment No: " << current->data->enrollmentNo << ", Age: " << current->data->age << endl;
            current = current->next;
        }
    }
};

int main() {
    List list;
    int choice = 0;
    string name;
    int enrollmentNo, age;

    int df = 1;
    while (df > 0) {
        cout << "Student Database Menu:\n";
        cout << "Enter 1 to Add New Student\n";
        cout << "Enter 2 to Delete Student\n";
        cout << "Enter 3 to Display All Students\n";
        cout << "Sort students.";
        cout << "Enter 5 to Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student's name: ";
                cin >> name;
                cout << "Enter enrollment number: ";
                cin >> enrollmentNo;
                cout << "Enter age: ";
                cin >> age;
                list.insert(new Student(name, enrollmentNo, age));
                break;
            case 2:
                cout << "Enter enrollment number of the student to delete: ";
                cin >> enrollmentNo;
                list.remove(enrollmentNo);
                break;
            case 3:
                cout << "All Students:\n";
                list.display();
                break;
            case 4:
                cout << "Sort Students by Age (Not Implemented)\n";
                break;
            case 5:
                df = 0;
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
