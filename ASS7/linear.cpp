#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- Linear Search ---
    cout << "--- Linear Search ---" << endl;
    
    // The array to be searched
    vector<int> arr = {15, 21, 8, 54, 32, 9, 41};
    int key_to_find = 32;

    bool found = false;
    int position = -1;

    // Iterate through the array from the beginning to the end
    for (int i = 0; i < arr.size(); ++i) {
        // If the current element matches the key
        if (arr[i] == key_to_find) {
            found = true;
            position = i;
            break; // Exit the loop once the key is found
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