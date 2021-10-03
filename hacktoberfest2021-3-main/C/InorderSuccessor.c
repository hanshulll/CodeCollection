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
struct Node* FindMin(struct Node* root){
    struct Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
struct Node* search(struct Node* root,int x){
    if(root==NULL)
        return NULL;
    else if(root->data==x)
        return root;
    else if(x < root->data)
        return search(root->left,x);
    else
        return search(root->right,x);
}
struct Node* getsuccessor(struct Node* root,int x){
    struct Node* current= search(root,x);
    if(current==NULL){
        return NULL;
    }
    else if(current->right!=NULL)
        return FindMin(current->right);
    else{
        struct Node* successor=NULL;
        struct Node* ancestor= root;
        while(ancestor!=current){
            if(current->data < ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                successor=ancestor;
                ancestor=ancestor->right;
            }
        }
        return successor;
    }
}
int main(){
    struct Node* root=NULL;
    root= Insert(root,5);
    root= Insert(root,6);
    root= Insert(root,9);
    root= Insert(root,7);
    root= Insert(root,45);
    struct Node* successor;
    successor=getsuccessor(root,6);
    printf("%d",successor->data);
}
