Exp 9
Write a program to check for balanced parentheses in a given expression.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check for balanced parentheses
bool areParenthesesBalanced(string expr) {
    stack<char> s;

    // Iterate through each character in the expression
    for (char& c : expr) {
        // If the character is an opening parenthesis, push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
            // If the character is a closing parenthesis
        else if (c == ')' || c == ']' || c == '}') {
            // If the stack is empty, there's no matching opening parenthesis, return false
            if (s.empty()) {
                return false;
            }

            // Get the top element from the stack
            char topChar = s.top();
            s.pop();

            // Check if the current closing parenthesis matches the top element of the stack
            if ((c == ')' && topChar != '(') || (c == ']' && topChar != '[') || (c == '}' && topChar != '{')) {
                return false;
            }
        }
    }

    // If the stack is empty after processing all characters, return true
    return s.empty();
}

int main() {
    string expr;

    // Input the expression
    cout << "Enter an expression: ";
    getline(cin, expr);

    // Check if parentheses are balanced
    if (areParenthesesBalanced(expr)) {
        cout << "Parentheses are balanced.\n";
    } else {
        cout << "Parentheses are not balanced.\n";
    }

    return 0;
}