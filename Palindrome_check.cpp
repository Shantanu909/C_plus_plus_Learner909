#include <iostream>
using namespace std;

class stk {
public:
    char s[50];
    int top;

    stk() {
        top = -1;
    }

    char pop() {
        if (top == -1) {
            cout << "Underflow";
            return '\0';
        } else {
            return s[top--];
        }
    }

    void push(char data) {
        if (top == sizeof(s) / sizeof(char) - 1) {
            cout << "Overflow";
        } else {
            top++;
            s[top] = data;
        }
    }
};

int main() {
    stk sobj;
    string input;

    cout << "Welcome to the program for String palindrome checking.\n";
    cout << "Please enter a string: ";
    cin >> input;

    for (char c : input) {
        sobj.push(c);
    }

    string reversed;

    while (sobj.top != -1) {
        reversed += sobj.pop();
    }

    if (input == reversed) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }

    return 0;
}
