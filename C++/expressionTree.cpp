//Github Profile: hortiprajwal
//C++ program to evaluate the expression Tree

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100

#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}

class Solution{
  public:
    int evalTree(node* root) {
      
        if(root==NULL)
            return 0;
        if(root->data!="+" && root->data!="-" && root->data!="*" && root->data!="/"){
            stringstream s(root->data);
            int x;
            s>>x;
            return x;
        }
        if(root->data=="+")
            return evalTree(root->left) + evalTree(root->right);
        else if(root->data=="-")
            return evalTree(root->left) - evalTree(root->right);
        else if(root->data=="*")
            return evalTree(root->left) * evalTree(root->right);
        else if(root->data=="/")
            return evalTree(root->left) / evalTree(root->right);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
