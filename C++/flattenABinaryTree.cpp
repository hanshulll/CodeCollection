// code to flatten to binary tree

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void Flatten(node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left != NULL){
        Flatten(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
          
        node* t = root->right;
        while(t->right!=NULL){
            t = t->right;
        }

        t->right = temp;
    }
    Flatten(root->right);
}

void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    Flatten(root);
    printInorder(root);   
    return 0;
}
