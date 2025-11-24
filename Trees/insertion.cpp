/*Unlike a list or an array, you do not get to choose
 where a node is inserted. The node's value automatically 
 determines its one and only correct position.*/
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

// --- 1. Recursive Insert Function ---
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


// --- 2. Iterative Insert Function ---
TreeNode* insertIterative(TreeNode* root, int dataToInsert) {
    
    TreeNode* newNode = new TreeNode(dataToInsert);

    if (root == nullptr) {
        return newNode;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr; 

    while (current != nullptr) {
        parent = current; 
        
        if (dataToInsert < current->data) {
            current = current->left;
        } else if (dataToInsert > current->data) {
            current = current->right;
        } else {
            delete newNode;
            return root;
        }
    }

    if (dataToInsert < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}


// --- Helper function to print the tree (Inorder) ---
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// --- Helper function to delete the tree ---
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}


// --- Main Function to Demonstrate ---
int main() {
    
    TreeNode* root = nullptr; 

    cout << "Inserting 10 (as root)..." << endl;
    root = insertRecursive(root, 10); 

    cout << "Inserting 5..." << endl;
    insertRecursive(root, 5); 

    cout << "Inserting 15..." << endl;
    insertRecursive(root, 15); 

    cout << "Inserting 7 (using iterative)..." << endl;
    insertIterative(root, 7); 
    
    cout << "Inserting 3 (using iterative)..." << endl;
    insertIterative(root, 3); 

    // Tree should be:
    //      10
    //     /  \
    //    5    15
    //   / \
    //  3   7

    cout << "\nInorder Traversal (should be sorted):" << endl;
    printInorder(root); // Prints: 3 5 7 10 15
    cout << endl;

    // Clean up memory
    deleteTree(root);
    return 0;
}
