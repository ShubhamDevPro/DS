Exp 7
Write a program to implement stack using arrays and linked lists.
#include <iostream>
// Node structure for linked list implementation
struct Node {
    int data;
    Node* next;
};
// Stack class using array
class ArrayStack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;
public:
    ArrayStack() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }
    // Function to push element onto the stack
    void push(int val) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    // Function to pop element from the stack
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1; // Returning -1 for underflow
        }
        return arr[top--];
    }
    // Function to check if stack is empty
    bool isEmpty() {
        return top < 0;
    }
    // Function to get the top element of the stack
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty\n";
            return -1; // Returning -1 for empty stack
        }
        return arr[top];
    }
};
// Stack class using linked list
class LinkedListStack {
private:
    Node* top;
public:
    LinkedListStack() {
        top = nullptr; // Initialize top pointer to nullptr to indicate an empty stack
    }
    // Function to push element onto the stack
    void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    // Function to pop element from the stack
    int pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow\n";
            return -1; // Returning -1 for underflow
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    // Function to check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    // Function to get the top element of the stack
    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is empty\n";
            return -1; // Returning -1 for empty stack
        }
        return top->data;
    }
};
int main() {
    // ArrayStack implementation
    ArrayStack arrStack;
    arrStack.push(10);
    arrStack.push(20);
    arrStack.push(30);
    std::cout << "ArrayStack:\n";
    while (!arrStack.isEmpty()) {
        std::cout << arrStack.pop() << " ";
    }
    std::cout << std::endl;
    // LinkedListStack implementation
    LinkedListStack llStack;
    llStack.push(40);
    llStack.push(50);
    llStack.push(60);
    std::cout << "LinkedListStack:\n";
    while (!llStack.isEmpty()) {
        std::cout << llStack.pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}