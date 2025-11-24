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

// --- Helper: findMin (Needed for Deletion Case 3) ---
TreeNode* findMin(TreeNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// --- The Main Deletion Function ---
TreeNode* deleteNode(TreeNode* node, int dataToDelete) {
    
    // Base Case: Tree is empty or node not found
    if (node == nullptr) {
        return node;
    }

    // --- 1. Find the node ---
    if (dataToDelete < node->data) {
        node->left = deleteNode(node->left, dataToDelete);
    } else if (dataToDelete > node->data) {
        node->right = deleteNode(node->right, dataToDelete);
    } 
    // --- 2. Found the node. Now handle the 3 deletion cases ---
    else {
        
        // 
        // Case 1: Leaf node (no children)
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // 
        // Case 2: One child (only right child)
        else if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp; // The parent will now point to this child
        }
        // Case 2: One child (only left child)
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp; // The parent will now point to this child
        }

        // 
        // Case 3: Two children
        else {
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* successor = findMin(node->right);

            // Copy the successor's data into this node
            node->data = successor->data;

            // Now, delete the successor (which is a duplicate)
            // from the right subtree. This will be a Case 1 or 2 deletion.
            node->right = deleteNode(node->right, successor->data);
        }
    }
    return node; // Return the (possibly updated) node pointer
}



// --- Helper function to print the tree (Inorder) ---
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// --- Helper function to delete the entire tree (for cleanup) ---
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// --- Helper function to insert (to build the test tree) ---
TreeNode* insertRecursive(TreeNode* node, int dataToInsert) {
    if (node == nullptr) {
        return new TreeNode(dataToInsert);
    }
    if (dataToInsert < node->data) {
        node->left = insertRecursive(node->left, dataToInsert);
    } else if (dataToInsert > node->data) {
        node->right = insertRecursive(node->right, dataToInsert);
    }
    return node;
}


// --- Main Function to Demonstrate All 3 Cases ---
int main() {
    
    // Build a good test tree
    //        10
    //       /  \
    //      5    20
    //     / \   / \
    //    3   7 15  25
    //          /
    //         12 
    TreeNode* root = nullptr;
    root = insertRecursive(root, 10);
    insertRecursive(root, 5);
    insertRecursive(root, 20);
    insertRecursive(root, 3);
    insertRecursive(root, 7);
    insertRecursive(root, 15);
    insertRecursive(root, 25);
    insertRecursive(root, 12); // This will be the child of 15

    cout << "Initial tree: ";
    printInorder(root); // 3 5 7 10 12 15 20 25
    cout << endl;

    // --- Test 1: Delete a leaf node (3) ---
    cout << "Deleting 3 (Case 1: Leaf)..." << endl;
    root = deleteNode(root, 3);
    cout << "Tree now: ";
    printInorder(root); // 5 7 10 12 15 20 25
    cout << endl;

    // --- Test 2: Delete a node with one child (15) ---
    cout << "Deleting 15 (Case 2: One Child)..." << endl;
    root = deleteNode(root, 15);
    cout << "Tree now: ";
    printInorder(root); // 5 7 10 12 20 25
    cout << endl;

    // --- Test 3: Delete a node with two children (10) ---
    cout << "Deleting 10 (Case 3: Two Children)..." << endl;
    root = deleteNode(root, 10);
    cout << "Tree now: ";
    printInorder(root); // 5 7 12 20 25 (12 is the successor)
    cout << endl;


    // Clean up remaining memory
    deleteTree(root);
    return 0;
}
