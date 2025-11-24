#include <iostream>
#include <vector>
#include <utility> // For std::swap

using namespace std;

int main() {
    // --- Bubble Sort ---
    cout << "--- Bubble Sort ---" << endl;
    
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for comparisons and swaps
        // The n-i-1 is an optimization, as the last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}