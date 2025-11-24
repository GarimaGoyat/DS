#include <iostream>
#include <vector>
#include <utility> // Required for std::swap

using namespace std;

int main() {
    // --- Insertion Sort using two for loops ---
    cout << "--- Insertion Sort (using two for loops) ---" << endl;

    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // The outer loop picks an element to be inserted into the sorted part.
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}


/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- Insertion Sort ---
    cout << "--- Insertion Sort ---" << endl;

    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // Start from the second element (the first element is a sorted sub-array of size 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key,
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}*/