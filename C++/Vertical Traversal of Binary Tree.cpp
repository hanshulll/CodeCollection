class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
 
        //Your code here
    vector<int> res;
    map<int,vector<int>> m;
    queue<pair<Node*,int>> q;
    vector<int> verticalOrder(Node *root)
    {
        q.push({root,0});
        while(!q.empty())
        {
            Node* temp = q.front().first;
            int d = q.front().second;
            m[d].push_back(temp->data);
            q.pop();
            if(temp->left != NULL) 
                q.push({temp->left,d-1});
            if(temp->right != NULL) 
                q.push({temp->right,d+1});
        }
        for(auto i : m)
        {
           for(auto j : i.second)
                res.push_back(j);
        }
        return res;
    }   
};
