Exp 8 Write a program to reverse a sentence using stack.
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to reverse a sentence using stack
string reverseSentence(string sentence) {
    stack<string> wordsStack;
    string word = "";

    // Iterate through each character in the sentence
    for (char& c : sentence) {
        // If the character is not a space, append it to the current word
        if (c != ' ') {
            word += c;
        }
            // If the character is a space and the current word is not empty, push it onto the stack
        else if (!word.empty()) {
            wordsStack.push(word);
            word = ""; // Reset the current word
        }
    }

    // Push the last word onto the stack (if not empty)
    if (!word.empty()) {
        wordsStack.push(word);
    }

    string reversedSentence = "";

    // Pop each word from the stack and append it to the reversed sentence
    while (!wordsStack.empty()) {
        reversedSentence += wordsStack.top() + " ";
        wordsStack.pop();
    }

    // Remove the trailing space
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }

    return reversedSentence;
}

int main() {
    string sentence;

    // Input the sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Reverse the sentence
    string reversedSentence = reverseSentence(sentence);

    // Output the reversed sentence
    cout << "Reversed sentence: " << reversedSentence << endl;

    return 0;
}