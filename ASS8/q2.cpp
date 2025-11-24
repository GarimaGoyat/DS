#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int v){
        data=v;
        left=right=NULL;
    }
};

// insert node
Node* insertNode(Node *root, int x){
    if(root==NULL) return new Node(x);

    if(x < root->data) root->left = insertNode(root->left, x);
    else if(x > root->data) root->right = insertNode(root->right, x);

    return root;
}

// (a) recursive search
Node* searchRec(Node *root, int key){
    if(root==NULL || root->data==key) return root;

    if(key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

// (a) non-recursive search
Node* searchIter(Node *root, int key){
    while(root!=NULL){
        if(root->data == key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) maximum element
Node* maxNode(Node *root){
    while(root->right!=NULL)
        root = root->right;
    return root;
}

// (c) minimum element
Node* minNode(Node *root){
    while(root->left!=NULL)
        root = root->left;
    return root;
}

// (d) inorder successor
Node* inorderSuccessor(Node* root, Node* x){
    // case 1: right subtree exists
    if(x->right != NULL) return minNode(x->right);

    // case 2: search from root
    Node *succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else if(x->data > root->data){
            root = root->right;
        } else break;
    }
    return succ;
}

// (e) inorder predecessor
Node* inorderPredecessor(Node* root, Node* x){
    if(x->left != NULL) return maxNode(x->left);

    Node *pred = NULL;
    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        }
        else if(x->data < root->data){
            root = root->left;
        }
        else break;
    }
    return pred;
}

int main(){
    Node *root=NULL;
    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 5);
    insertNode(root, 15);

    Node *x = searchRec(root, 10);

    cout<<"Max: "<<maxNode(root)->data<<endl;
    cout<<"Min: "<<minNode(root)->data<<endl;

    cout<<"Successor of 10: "<<inorderSuccessor(root,x)->data<<endl;

    cout<<"Predecessor of 10: "<<inorderPredecessor(root,x)->data<<endl;
}
