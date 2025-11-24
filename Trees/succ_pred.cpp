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

// Helper: Finds the minimum node in a subtree
TreeNode* findMin(TreeNode* node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Helper: Finds the maximum node in a subtree
TreeNode* findMax(TreeNode* node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}


// --- Inorder Successor (No Parent Pointer) ---
// 
TreeNode* findSuccessor(TreeNode* root, TreeNode* nodeToFind) {
    if (nodeToFind == nullptr) return nullptr;

    // Case 1: Node has a right subtree.
    // Successor is the minimum value in that right subtree.
    if (nodeToFind->right != nullptr) {
        return findMin(nodeToFind->right);
    }

    // Case 2: Node has no right subtree.
    // Successor is an ancestor. We must search from the root.
    TreeNode* successor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (nodeToFind->data < current->data) {
            // This is a potential successor (last "left turn").
            successor = current;
            current = current->left;
        } else if (nodeToFind->data > current->data) {
            // Not a successor, just move right.
            current = current->right;
        } else {
            // We found the node, stop searching.
            break; 
        }
    }
    return successor;
}


// --- Inorder Predecessor (No Parent Pointer) ---
// 
TreeNode* findPredecessor(TreeNode* root, TreeNode* nodeToFind) {
    if (nodeToFind == nullptr) return nullptr;

    // Case 1: Node has a left subtree.
    // Predecessor is the maximum value in that left subtree.
    if (nodeToFind->left != nullptr) {
        return findMax(nodeToFind->left);
    }

    // Case 2: Node has no left subtree.
    // Predecessor is an ancestor. We must search from the root.
    TreeNode* predecessor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (nodeToFind->data > current->data) {
            // This is a potential predecessor (last "right turn").
            predecessor = current;
            current = current->right;
        } else if (nodeToFind->data < current->data) {
            // Not a predecessor, just move left.
            current = current->left;
        } else {
            // We found the node, stop searching.
            break;
        }
    }
    return predecessor;
}


// --- Main Function to Demonstrate ---
int main() {
    //      10
    //     /  \
    //    5    15
    //   / \
    //  3   7
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    // Get a pointer to the node we want to test (e.g., node 5)
    TreeNode* node5 = root->left;
    
    // --- Test Successor ---
    // Successor of 5 should be 7
    TreeNode* succ = findSuccessor(root, node5);
    if (succ != nullptr) {
        cout << "Successor of 5 is: " << succ->data << endl;
    } else {
        cout << "Successor of 5 not found." << endl;
    }

    // --- Test Predecessor ---
    // Predecessor of 5 should be 3
    TreeNode* pred = findPredecessor(root, node5);
    if (pred != nullptr) {
        cout << "Predecessor of 5 is: " << pred->data << endl;
    } else {
        cout << "Predecessor of 5 not found." << endl;
    }
    
    // --- Test Node with no right subtree (7) ---
    // Successor of 7 should be 10 (an ancestor)
    TreeNode* node7 = root->left->right;
    succ = findSuccessor(root, node7);
    cout << "Successor of 7 is: " << succ->data << endl;
    
    // --- Test Node with no left subtree (3) ---
    // Predecessor of 3 should be null
    TreeNode* node3 = root->left->left;
    pred = findPredecessor(root, node3);
    if (pred != nullptr) {
        cout << "Predecessor of 3 is: " << pred->data << endl;
    } else {
        cout << "Predecessor of 3 is null (correct)." << endl;
    }


    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/*findMin: It finds the successor when a node has a right subtree, 
as the successor is the smallest value in that right subtree.
findMax: It finds the predecessor when a node has a left subtree,
 as the predecessor is the largest value in that left subtree.*/