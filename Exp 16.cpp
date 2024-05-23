Exp 16 Write Program for Bubble sort, selection sort, quick sort, merge sort, insertion sort
#include <iostream>
#include <vector>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// Function to perform Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    // Bubble Sort
    vector<int> arrBubble = arr;
    bubbleSort(arrBubble);
    cout << "Sorted array using Bubble Sort: ";
    for (int num : arrBubble) {
        cout << num << " ";}
    cout << endl;
    // Selection Sort
    vector<int> arrSelection = arr;
    selectionSort(arrSelection);
    cout << "Sorted array using Selection Sort: ";
    for (int num : arrSelection) {
        cout << num << " ";}
    cout << endl;
    // Quick Sort
    vector<int> arrQuick = arr;
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    cout << "Sorted array using Quick Sort: ";
    for (int num : arrQuick) {
        cout << num << " ";}
    cout << endl;
    // Merge Sort
    vector<int> arrMerge = arr;
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int num : arrMerge) {
        cout << num << " ";}
    cout << endl;
    // Insertion Sort
    vector<int> arrInsertion = arr;
    insertionSort(arrInsertion);
    cout << "Sorted array using Insertion Sort: ";
    for (int num : arrInsertion) {
        cout << num << " ";}
    cout << endl;
    return 0;}

