#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // deterministic: last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

// Deterministic quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Randomized quicksort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main() {
    srand(time(0)); // seed for randomness

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    vector<int> arr1 = arr; // copy for deterministic quicksort
    vector<int> arr2 = arr; // copy for randomized quicksort

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr1, 0, arr1.size() - 1);
    cout << "\nSorted array using Deterministic Quick Sort:\n";
    printArray(arr1);

    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    cout << "\nSorted array using Randomized Quick Sort:\n";
    printArray(arr2);

    return 0;
}
