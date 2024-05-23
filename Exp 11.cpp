Exp 11
Write a program to implement Tower of Hanoi using stacks.
#include <iostream>
#include <stack>

using namespace std;

// Function to move a disk from one tower to another
void moveDisk(stack<int>& source, stack<int>& dest, char sourceName, char destName) {
    int topDisk = source.top();
    source.pop();
    dest.push(topDisk);
    cout << "Move disk " << topDisk << " from " << sourceName << " to " << destName << endl;
}

// Function to perform Tower of Hanoi recursively
void towerOfHanoi(int numDisks, stack<int>& source, stack<int>& aux, stack<int>& dest, char sourceName, char auxName, char destName) {
    if (numDisks == 1) {
        moveDisk(source, dest, sourceName, destName);
    } else {
        towerOfHanoi(numDisks - 1, source, dest, aux, sourceName, destName, auxName);
        moveDisk(source, dest, sourceName, destName);
        towerOfHanoi(numDisks - 1, aux, source, dest, auxName, sourceName, destName);
    }
}

int main() {
    int numDisks;

    // Input the number of disks
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    // Create stacks for each tower
    stack<int> source, aux, dest;

    // Initialize the source tower with disks
    for (int i = numDisks; i >= 1; --i) {
        source.push(i);
    }

    // Call the Tower of Hanoi function
    towerOfHanoi(numDisks, source, aux, dest, 'A', 'B', 'C');

    return 0;
}
