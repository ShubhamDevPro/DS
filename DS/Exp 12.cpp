


Exp 12 Write a program to implement Linear Queue using
        A ) Array

#include <iostream>

using namespace std;

#define MAX_SIZE 100

class ArrayQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = data;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display(); // Output: Queue: 10 20 30 40

    q.dequeue();
    q.dequeue();
    q.display(); // Output: Queue: 30 40
    cout << "Front element: " << q.peek() << endl; // Output: Front element: 30
    return 0;
}
Exp 12 Write a program to implement Linear Queue using
        B) Linked Lists

#include <iostream>
using namespace std;
// Node structure for Linked List
struct Node {
    int data;
    Node* next;
};
class LinkedListQueue {
private:
    Node* front;
    Node* rear;
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }
    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }
    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedListQueue q;

    q.enqueue(50);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(55);

    q.display(); // Output: Queue: 50 30 40 55

    q.dequeue();
    q.dequeue();

    q.display(); // Output: Queue: 40 55
    cout << "Front element: " << q.peek() << endl; // Output: Front element: 40
    return 0;
}