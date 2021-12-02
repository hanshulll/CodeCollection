#include <bits/stdc++.h>
using namespace std;

//O(N^2) O(N)

//we traverse through pre[] and for each ele we check if it's in left of curr root or right.. and acc. to that we build left or
//right subtree... for each left and right recursive call we only send st and end acc. to ele's pos. in in[]

int search(int in[], int st, int end, int curr)//return pre[]'s ele's pos. in in[]
{
    for (int i = st; i <= end; i++)
    {
        if (in[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *build(int in[], int pre[], int st, int end, int &predex)//st and end are for in[]... 
{
    if (st > end)//if at any point st > end.. that means we don't have any ele left in in[] for next subtree
    {
        return NULL;//so return NULL(end of subtree)
    }

    int curr = pre[predex];//we store curr ele of pre[]
    predex++;//increase index for next call
    Node *root = new Node(curr);//make node

    if (st == end)//if st == end.. that means only one ele left in in[].. so no more eles for left or right subtree
    {
        return root;//so just return the node and don't go further calling left and right recursive calls
    }

    int pos = search(in, st, end, curr);//store the pos of ele in in[]

    //here we call left first then right
    root->left = build(in, pre, st, pos - 1, predex);//left subtree's ele are on left side of cur root in in[].. so send st, pos-1
    root->right = build(in, pre, pos + 1, end, predex);//right subtree's ele are on right side of cur root in in[]..so send pos+1, end

    return root;//atlast return the construct root
}

Node *buildTree(int in[], int pre[], int n)
{
    int predex = 0;//as pre[] has root at 1st ele.. we start from index 0
    Node *toReturn = build(in, pre, 0, n - 1, predex);
    return toReturn;
}