#github-username: Yashika27

// Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Problem Description: Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
// Solution is as follows:

vector<int> leftView(Node *root)
{
   queue<Node*>q;
   vector<int>v;
    if (root == NULL)
        return v;
   q.push(root);
   
   
   while(!q.empty())
   {
       int l1 = q.size();
       int l = l1;
    //   int i=0;
       while (l > 0)
       {
           Node* temp = q.front();
           q.pop();
           if(l==l1)
           v.push_back(temp->data);
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           l--;
       }
   }
   return v;
}
