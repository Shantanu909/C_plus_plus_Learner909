#include <iostream>
#include <stack>

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to infix
std::string postfixToInfix(const std::string& postfix) {
    std::stack<std::string> operandStack;

    for (char c : postfix) {
        if (isalnum(c)) {
            operandStack.push(std::string(1, c)); // Operand, push to the stack
        } else if (isOperator(c)) {
            if (operandStack.size() < 2) {
                std::cerr << "Invalid postfix expression." << std::endl;
                return "";
            }
            std::string operand2 = operandStack.top();
            operandStack.pop();
            std::string operand1 = operandStack.top();
            operandStack.pop();
            std::string expression = "(" + operand1 + c + operand2 + ")";
            operandStack.push(expression);
        }
    }

    if (operandStack.size() != 1) {
        std::cerr << "Invalid postfix expression." << std::endl;
        return "";
    }

    return operandStack.top();
}

int main() {
    std::string postfixExpression;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfixExpression;

    std::string infixExpression = postfixToInfix(postfixExpression);
    if (!infixExpression.empty()) {
        std::cout << "Infix expression: " << infixExpression << std::endl;
    }

    return 0;
}
