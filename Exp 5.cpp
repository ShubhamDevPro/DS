Exp 5
Write a program to create a doubly linked list of n nodes and perform:
a. Insertion at the beginning
b. Insertion at the end
c. Insertion at the specific location
        d. Deletion from the beginning
e. Deletion from the end
f. Deletion from the specific location
#include <iostream>
// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    // Function to insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // Function to insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // Function to insert at a specific location
    void insertAtLocation(int val, int pos) {
        if (pos <= 0) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
    }
    // Function to delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }
    // Function to delete from the end
    void deleteFromEnd() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
    // Function to delete from a specific location
    void deleteFromLocation(int pos) {
        if (pos <= 0 || !head) {
            std::cout << "List is empty or invalid position." << std::endl;
            return;
        }
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (!temp || !temp->next) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next) {
            temp->next->prev = temp;
        } else {
            tail = temp;
        }
        delete toDelete;
    }
    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    DoublyLinkedList list;
    // Insertion at the beginning
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    std::cout << "List after insertion at the beginning: ";
    list.display();
    // Insertion at the end
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    std::cout << "List after insertion at the end: ";
    list.display();
    // Insertion at a specific location
    list.insertAtLocation(10, 3);
    std::cout << "List after insertion at position 3: ";
    list.display();
    // Deletion from the beginning
    list.deleteFromBeginning();
    std::cout << "List after deletion from the beginning: ";
    list.display();
    // Deletion from the end
    list.deleteFromEnd();
    std::cout << "List after deletion from the end: ";
    list.display();
    // Deletion from a specific location
    list.deleteFromLocation(3);
    std::cout << "List after deletion from position 3: ";
    list.display();
    return 0;
}