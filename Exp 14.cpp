Exp 14 Write a program to implement Doubly Ended Queue using
(A)	Array
#include <iostream>

using namespace std;

#define MAX_SIZE 100

class ArrayDeque {
private:
    int deque[MAX_SIZE];
    int front, rear;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    // Function to add an element at the front of the deque
    void addFront(int data) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = data;
    }

    // Function to add an element at the rear of the deque
    void addRear(int data) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = data;
    }

    // Function to remove an element from the front of the deque
    void removeFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Function to remove an element from the rear of the deque
    void removeRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    // Function to get the front element of the deque
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return deque[front];
    }

    // Function to get the rear element of the deque
    int peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return deque[rear];
    }

    // Function to display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << deque[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    ArrayDeque dq;

    dq.addFront(10);
    dq.addFront(20);
    dq.addRear(30);
    dq.addRear(40);

    dq.display(); // Output: Deque: 20 10 30 40

    dq.removeFront();
    dq.removeRear();

    dq.display(); // Output: Deque: 10 30

    cout << "Front element: " << dq.peekFront() << endl; // Output: Front element: 10
    cout << "Rear element: " << dq.peekRear() << endl;   // Output: Rear element: 30

    return 0;
}
Exp 14 Write a program to implement Doubly Ended Queue using
(B)	Linked Lists
#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Deque class
class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Insert an element at the front of the deque
    void pushFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    // Insert an element at the back of the deque
    void pushBack(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    // Remove an element from the front of the deque
    int popFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }

        Node* temp = front;
        int data = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    // Remove an element from the back of the deque
    int popBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }

        Node* temp = rear;
        int data = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get the back element of the deque
    int getBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Print the contents of the deque
    void printDeque() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.pushFront(10);
    deque.pushBack(20);
    deque.pushFront(5);
    deque.pushBack(30);

    cout << "Deque after insertion: ";
    deque.printDeque();

    cout << "Front element: " << deque.getFront() << endl;
    cout << "Back element: " << deque.getBack() << endl;

    deque.popFront();
    deque.popBack();

    cout << "Deque after deletion: ";
    deque.printDeque();

    return 0;
}