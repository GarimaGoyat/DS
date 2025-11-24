#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

int main() {
    // --- Binary Search ---
    cout << "--- Binary Search ---" << endl;
    
    // The array MUST be sorted for binary search
    vector<int> arr = {8, 9, 15, 21, 32, 41, 54};
    int key_to_find = 21;

    int low = 0;
    int high = arr.size() - 1;
    bool found = false;
    int position = -1;

    // Loop until the search interval is valid
    while (low <= high) {
        // Calculate the middle index to avoid potential overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == key_to_find) {
            found = true;
            position = mid;
            break; // Key found
        } else if (arr[mid] < key_to_find) {
            // If key is greater, ignore the left half
            low = mid + 1;
        } else {
            // If key is smaller, ignore the right half
            high = mid - 1;
        }
    }
    
    // Display the result
    if (found) {
        cout << "Key " << key_to_find << " found at position: " << position << endl;
    } else {
        cout << "Key " << key_to_find << " not found in the array." << endl;
    }

    return 0;
}