#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int v){ data=v; left=right=NULL; }
};

Node* insertNode(Node* root, int x){
    if(root==NULL) return new Node(x);
    if(x < root->data) root->left = insertNode(root->left,x);
    else if(x > root->data) root->right = insertNode(root->right,x);
    return root;
}

Node* minNode(Node *root){
    while(root->left) root=root->left;
    return root;
}

// delete node
Node* deleteNode(Node* root, int key){
    if(root==NULL) return NULL;

    if(key < root->data) root->left = deleteNode(root->left,key);
    else if(key > root->data) root->right = deleteNode(root->right,key);
    else{
        // 1 child or no child
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;

        // 2 children
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

// max depth
int maxDepth(Node* root){
    if(root==NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// min depth
int minDepth(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL) return 1 + minDepth(root->right);
    if(root->right==NULL) return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root=NULL;

    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);

    root = deleteNode(root, 10);

    cout<<"Max depth: "<<maxDepth(root)<<endl;
    cout<<"Min depth: "<<minDepth(root)<<endl;
}
