#include <iostream>
using namespace std;

// --- 1. The TreeNode Class ---
// A simple class to define our tree node.
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

// --- 2. Find Minimum Value (Iterative) ---
// Simplest and most efficient way.
TreeNode* findMin(TreeNode* root) {
    // If the tree is empty, return null.
    if (root == nullptr) {
        return nullptr;
    }

    // Keep moving left until we find the last node.
    TreeNode* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    
    // 'current' is now the leftmost node.
    return current;
}

// --- 3. Find Maximum Value (Iterative) ---
// Simplest and most efficient way.
TreeNode* findMax(TreeNode* root) {
    // If the tree is empty, return null.
    if (root == nullptr) {
        return nullptr;
    }

    // Keep moving right until we find the last node.
    TreeNode* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    
    // 'current' is now the rightmost node.
    return current;
}

// --- 4. Find Minimum Value (Recursive) ---
// A recursive alternative.
TreeNode* findMinRecursive(TreeNode* node) {
    // Base Case 1: Tree is empty
    if (node == nullptr) {
        return nullptr;
    }
    // Base Case 2: We are at the leftmost node
    if (node->left == nullptr) {
        return node;
    }
    
    // Recursive Step: Keep going left
    return findMinRecursive(node->left);
}

// --- 5. Find Maximum Value (Recursive) ---
// A recursive alternative.
TreeNode* findMaxRecursive(TreeNode* node) {
    // Base Case 1: Tree is empty
    if (node == nullptr) {
        return nullptr;
    }
    // Base Case 2: We are at the rightmost node
    if (node->right == nullptr) {
        return node;
    }
    
    // Recursive Step: Keep going right
    return findMaxRecursive(node->right);
}


// --- 6. Main Function to Demonstrate ---
int main() {
    // Build the same simple tree:
    //      10
    //     /  \
    //    5    15
    //   /
    //  3
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);

    cout << "--- Min/Max Demo ---" << endl;

    // --- Find Minimum ---
    TreeNode* minNode = findMin(root); // Using the iterative version
    if (minNode != nullptr) {
        cout << "Minimum value (Iterative): " << minNode->data << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    // --- Find Maximum ---
    TreeNode* maxNode = findMax(root); // Using the iterative version
    if (maxNode != nullptr) {
        cout << "Maximum value (Iterative): " << maxNode->data << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    // --- You can test the recursive versions too ---
    // TreeNode* minNodeRec = findMinRecursive(root);
    // cout << "Minimum value (Recursive): " << minNodeRec->data << endl;
    //
    // TreeNode* maxNodeRec = findMaxRecursive(root);
    // cout << "Maximum value (Recursive): " << maxNodeRec->data << endl;


    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
