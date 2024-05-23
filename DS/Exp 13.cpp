
Exp 13
Write a program to implement Circular Queue using
(A)	Array

#include <iostream>

using namespace std;

#define MAX_SIZE 5

class CircularQueueArray {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueueArray() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
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
            rear = (rear + 1) % MAX_SIZE;
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
            front = (front + 1) % MAX_SIZE;
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
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    CircularQueueArray cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); // Overflow

    cq.display(); // Output: Queue: 10 20 30 40

    cq.dequeue();
    cq.dequeue();

    cq.display(); // Output: Queue: 30 40

    cout << "Front element: " << cq.peek() << endl; // Output: Front element: 30

    return 0;
}
Exp 13 Implement Circular Queue using
(B)	 Linked Lists
#include <iostream>

using namespace std;

// Node structure for the Circular Queue Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    CircularQueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Make the new node point to itself in a circular manner
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make rear point back to front in a circular manner
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
            rear->next = front; // Update rear to point back to front after dequeuing
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
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main() {
    CircularQueueLinkedList cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cq.display(); // Output: Queue: 10 20 30 40

    cq.dequeue();
    cq.dequeue();

    cq.display(); // Output: Queue: 30 40

    cout << "Front element: " << cq.peek() << endl; // Output: Front element: 30

    return 0;
}



