#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val; 
        left = nullptr; 
        right = nullptr;
    }
};

TreeNode* searchRecursive(TreeNode* node, int target) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == target) {
        return node;
    }

    if (target < node->data) {
        return searchRecursive(node->left, target);
    } else {
        return searchRecursive(node->right, target);
    }
}

TreeNode* searchIterative(TreeNode* root, int target) {
    TreeNode* current = root;

    while (current != nullptr) {
        if (current->data == target) {
            return current;
        }

        if (target < current->data) {
            current = current->left;
        } 
        else {
            current = current->right;
        }
    }
    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);

    // --- Demo 1: Find a value that exists (15) ---

    int targetToFind = 15;
    cout << "Searching for " << targetToFind << " (Recursive)..." << endl;
    
    TreeNode* result1 = searchRecursive(root, targetToFind);
    
    if (result1 != nullptr) {
        cout << "Found: " << result1->data << endl;
    } else {
        cout << "Not found." << endl;
    }

    // --- Demo 2: Find a value that DOESN'T exist (99) ---

    int targetToFind2 = 99;
    cout << "\nSearching for " << targetToFind2 << " (Iterative)..." << endl;
    
    TreeNode* result2 = searchIterative(root, targetToFind2);
    
    if (result2 != nullptr) {
        cout << "Found: " << result2->data << endl;
    } else {
        cout << "Not found." << endl;
    }

    // Clean up memory (optional for this simple example, but good practice)

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

