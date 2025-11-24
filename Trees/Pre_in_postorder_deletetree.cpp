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

void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "Deleting node: " << node->data << endl;
    delete node;
}

int main() {
    TreeNode* root = nullptr;

    root = new TreeNode(10);

    root->left = new TreeNode(5);

    root->right = new TreeNode(15);
    
    root->left->left = new TreeNode(3);

    cout << "--- Traversal Demo ---" << endl;

    cout << "Inorder (L, Root, R):   ";
    printInorder(root); 
    cout << endl;

    cout << "Preorder (Root, L, R):  ";
    printPreorder(root); 
    cout << endl;

    cout << "Postorder (L, R, Root): ";
    printPostorder(root); 
    cout << endl;

    cout << "\n--- Deleting Tree ---" << endl;
    deleteTree(root);
    
    return 0;
}

    // After deleteTree(root) is called, all memory is freed.
    // The manual lines below are no longer needed.

    // delete root->left->left;
    // delete root->left;
    // delete root->right;
    // delete root;

