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

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    cout << "Root node value: " << root->data << endl;
    cout << "Left child value: " << root->left->data << endl;
    cout << "Right child value: " << root->right->data << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
