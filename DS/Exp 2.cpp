Exp 2
Write a program that initializes an array with ten random integers and then prints four lines of output, containing:
a. Every odd element
        b. Every element at an even index
c. All elements in reverse order Only the first and last element
#include <iostream>
#include <cstdlib>
#include <ctime>
// Function to generate a random integer between min and max (inclusive)
int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}
int main() {
    // Seed the random number generator
    srand(time(nullptr));
    // Initialize an array with ten random integers
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = generateRandomInt(1, 100); // Adjust the range as needed
    }
    // Print every odd element
    std::cout << "Every odd element:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 != 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    // Print every element at an even index
    std::cout << "Every element at an even index:" << std::endl;
    for (int i = 0; i < 10; i += 2) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // Print all elements in reverse order, only the first and last element
    std::cout << "All elements in reverse order (only the first and last element):" << std::endl;
    std::cout << arr[9] << " " << arr[0] << std::endl;
    return 0;
}