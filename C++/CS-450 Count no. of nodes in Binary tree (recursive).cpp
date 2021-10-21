#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lc = count(root->left);
    int rc = count(root->right);

    int c = lc + rc + 1;

    return c;
}

int main()
{
    /*
                1
               / \
              2   3
             / \ / \
            4  5 6  7 
    */
   //to construct above tree.. below is code

    //level 0
    Node* root = new Node(1);
    //level1
    root->left = new Node(2);
    root->right = new Node(3);
    //level2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<count(root)<<endl;
}