#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int v){ data=v; left=right=NULL; }
};

bool isBSTUtil(Node *root, int minVal, int maxVal){
    if(root==NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node *root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(30);

    if(isBST(root)) cout<<"BST";
    else cout<<"Not BST";
}
