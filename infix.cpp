#include <iostream>
using namespace std;
class Stack {
private:
    char* stack;
    int capacity;
    int top;

public:
    Stack(int capacity) {
        stack = new char[capacity];
        top = -1;
    }

   

    void push(char c) {
        if (top < capacity - 1)
            stack[++top] = c;
    }

    char pop() {
        if (top >= 0)
            return stack[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0)
            return stack[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(const string& expression) {
    string postfix = "";
    Stack operators(expression.size());

    for (char c : expression) {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                postfix += operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && operators.peek() != '(' &&
                   precedence(operators.peek()) >= precedence(c)) {
                postfix += operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack values(postfix.size());

    for (char c : postfix) {
        if (isalnum(c)) {
            values.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = values.pop();
            int operand1 = values.pop();
            switch (c) {
                case '+':
                    values.push(operand1 + operand2);
                    break;
                case '-':
                    values.push(operand1 - operand2);
                    break;
                case '*':
                    values.push(operand1 * operand2);
                    break;
                case '/':
                    values.push(operand1 / operand2);
                    break;
            }
        }
    }

    return values.pop();
}

int main() {
	cout<<"Please enter your infix code";
    string infixExpression;
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);

    cout << postfixExpression << endl;

    int postfixResult = evaluatePostfix(postfixExpression);

    cout << postfixResult << endl;

    return 0;
}
