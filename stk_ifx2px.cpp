#include <iostream>

class CharStack {
private:
    char* data;
    int top;
    int maxSize;

public:
    CharStack(int size) : top(-1), maxSize(size) {
        data = new char[size];
    }

    ~CharStack() {
        delete[] data;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(char value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return data[top--];
        }
        return '\0'; // You can choose a different way to handle this error.
    }

    char peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0'; // You can choose a different way to handle this error.
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For other characters (operands)
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    CharStack operatorStack(infix.length());

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Operand, add to the output
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == '(')
                operatorStack.pop();
        } else if (isOperator(c)) {
            while (!operatorStack.isEmpty() && precedence(c) <= precedence(operatorStack.peek())) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
