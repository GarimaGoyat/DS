#include <iostream>
#include <vector>
#include <utility> // For std::swap

using namespace std;

int main() {
    // --- Selection Sort ---
    cout << "--- Selection Sort ---" << endl;

    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    
    return 0;
}