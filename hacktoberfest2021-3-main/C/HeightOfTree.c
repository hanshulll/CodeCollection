#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* left;
    int data;
    struct Node* right;

};
struct Node* getNewNode(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Node* Insert(struct Node* root,int x){
    struct Node* newNode= getNewNode(x);
    if(root==NULL){
        root=newNode;
        return root;
    }
    else if(x < root->data){
        root->left=Insert(root->left,x);
    }
    else{
        root->right= Insert(root->right,x);
    }
    return root;
}
int max(int a , int b){
    return a>b?a:b;
}
int BSTHeight(struct Node* root){
    if(root==NULL){
        return -1;
    }
    int leftheight,rightheight;
    leftheight=BSTHeight(root->left);
    rightheight=BSTHeight(root->right);
    return max(leftheight,rightheight)+1;
}
int main(){
    struct Node* root=NULL;
    root= Insert(root,5);
    root= Insert(root,4);
    root= Insert(root,3);
    root= Insert(root,2);
    root= Insert(root,1);
    root= Insert(root,9);
    root= Insert(root,7);
    root= Insert(root,45);
    int p,q;
    p=BSTHeight(root);
    printf("Height of the tree is %d",p);
    return 0;
}
