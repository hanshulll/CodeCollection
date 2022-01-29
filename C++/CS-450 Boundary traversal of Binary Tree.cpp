#include <bits/stdc++.h>
using namespace std;

//O(N) O(N)
//read notebook for question explanation

//1 - push root in ans array
//2 - push all left side ele (top to bottom) except leaf nodes and root
//3 - push all leaf nodes from left to right
//4 - push all right side nodes in reverse order (bottom to up) except leaf nodes and root

void leftN(Node *root, vector<int> &ans)//this does the 2nd task
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)//first check for left and if no left then only check for right
    {
        ans.push_back(root->data);//push in ans array
        leftN(root->left, ans);//then call for it's left
    }
    else if (root->right != NULL)//if no left present then it is possible that right might be included in left view so check that too
    {
        ans.push_back(root->data);
        leftN(root->right, ans);
    }
}

void leafN(Node *root, vector<int> &ans)//this does the 3rd task
{
    if (root == NULL)
    {
        return;
    }

    leafN(root->left, ans);//call for left side first as we need leaf nodes from left to right

    if (root->left == NULL && root->right == NULL)//if for any node both left and right is NULL then it is leaf node
    {
        ans.push_back(root->data);//push in ans
        return;
    }

    leafN(root->right, ans);//then call for right
}

void rightN(Node *root, vector<int> &ans)//this does the 4th task
{
    if (root == NULL)
    {
        return;
    }

    if (root->right != NULL)////first check for right and if no left then only check for left
    {
        rightN(root->right, ans);//call first
        ans.push_back(root->data);//then push in ans as we need right side in reverse order
    }
    else if (root->left != NULL)//if no right present then it is possible that left might be included in right view so check that too
    {
        rightN(root->left, ans);
        ans.push_back(root->data);
    }
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);//this does 1st task

    if (root->left == NULL && root->right == NULL)//if tree only has root.. then return it..otherwise.. leafN() will also put root in
    //ans array as it is also leaf node.... so if only one node in tree,... just return ans array now
    {
        return ans;
    }

    leftN(root->left, ans);//call for root->left as we dont want to include root in left view.. root is already in ans array
    leafN(root, ans);//leaf nodes
    rightN(root->right, ans);//call for root->right as we dont want to include root in right view.. root is already in ans array

    return ans;//return ans
}

int main()
{

}