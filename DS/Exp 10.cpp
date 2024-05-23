Lab – 10
- Write a program to convert infix expressions to prefix and postfix expressions.
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Function to check if a character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}
// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    // Iterate through each character in the infix expression
    for (char& c : infix) {
        // If character is an operand, add it to the postfix expression
        if (isOperand(c)) {
            postfix += c;}
            // If character is an opening parenthesis, push it onto the stack
        else if (c == '(') {
            s.push(c);}
            // If character is a closing parenthesis, pop and add operators from the stack to the postfix expression until an opening parenthesis is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }}
            // If character is an operator
        else if (isOperator(c)) {
            // Pop and add operators from the stack to the postfix expression until an operator with lower precedence or an opening parenthesis is encountered
            while (!s.empty() && getPrecedence(c) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }}

    // Pop and add remaining operators from the stack to the postfix expression
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    // Replace opening parentheses with closing parentheses and vice versa
    for (char& c : infix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
int main() {
    string infixExpression;
    // Input the infix expression
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
    // Convert infix expression to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    // Convert infix expression to prefix
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;
    return 0;
}