//Sum Tree
//Binary Tree: Check if Binary tree is Sum tree or not


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}



// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    
    bool isSumTree(Node* root)
    {
        if(root == NULL)
            return true;
        
        //first making function calls ad then processing this ensures that we start applying the lofic from leaf node
        bool res = isSumTree(root->left) && isSumTree(root->right);
            
        if(root->left && root->right)
        {
            if(root->left->data + root->right->data != root->data)
            {
                return false;
            }
            
            //storing the sum of left+right subtree in the current node
            root->data += root->right->data + root->left->data;
        }
        else if(root->left)
        {
            if(root->left->data != root->data)
            {
                return false;
            }
            
            //storing the value of left subtree in the current node
            root->data += root->left->data;
        }
        else if(root->right)
        {
            if(root->right->data != root->data)
            {
                return false;
            }
            
            //storing the value of right subtree in the current node
            root->data += root->right->data;
        }
        
        return res;
    }
};




int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}