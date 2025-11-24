#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// preorder: root → left → right
void preorder(Node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder: left → root → right
void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder: left → right → root
void postorder(Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    // simple tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout<<"Preorder: "; preorder(root); cout<<endl;
    cout<<"Inorder: "; inorder(root); cout<<endl;
    cout<<"Postorder: "; postorder(root); cout<<endl;
}
