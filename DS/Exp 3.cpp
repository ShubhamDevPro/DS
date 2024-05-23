Exp 3 Write a program to read numbers in an integer array of size 5 and display the following:
a. Sum of all the elements
        b. Sum of alternate elements in the array
        c. Second highest element in the array
#include <iostream>
#include <climits>
int main() {
    const int SIZE = 5;
    int arr[SIZE];
    // Input numbers into the array
    std::cout << "Enter " << SIZE << " integers:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> arr[i];
    }
    // Calculate sum of all elements
    int sumAll = 0;
    for (int i = 0; i < SIZE; ++i) {
        sumAll += arr[i];
    }
    // Calculate sum of alternate elements
    int sumAlternate = 0;
    for (int i = 0; i < SIZE; i += 2) {
        sumAlternate += arr[i];
    }
    // Find second highest element
    int max = INT_MIN;
    int secondMax = INT_MIN;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] != max) {
            secondMax = arr[i];
        }
    }
    // Display results
    std::cout << "Sum of all elements: " << sumAll << std::endl;
    std::cout << "Sum of alternate elements: " << sumAlternate << std::endl;
    std::cout << "Second highest element: " << secondMax << std::endl;
    return 0;
}