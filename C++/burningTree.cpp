// Mininum time required to burn a complete binary tree from a node

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
int findMaxDist(map<Node*,Node*> &m, Node* target){
    queue<Node*> q;
    q.push(target);
    map<Node*, int> vis;
    vis[target] = 1;
    int maxT = 0;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i=0;i<size;i++){
            auto temp = q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                fl = 1;
                vis[temp->left] = 1;
                q.push(temp->left);
            }
            if(temp->right && !vis[temp->right]){
                fl = 1;
                vis[temp->right] = 1;
                q.push(temp->right);
            }
            if(m[temp] && !vis[m[temp]]){
                fl = 1;
                vis[m[temp]] = 1;
                q.push(m[temp]);
            }
        }
        if(fl) maxT++;
    }
    return maxT;
}
node* bfsToMapParent(node* root, map<node*,node*> &m, int start){
    queue<node*> q;
    q.push(root);
    node* res;
    while(!q.empty()){
        node* temp = q.front();
        if(temp->data==start) res = temp;
        q.pop();
        if(temp->left){
            m[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            m[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}
int timeToBurnTree(node* root, int start){
    map<node*, node*> m;
    node* target = bfsToMapParent(root,m,start);
    int maxT = findMaxDist(m,target);
    return maxT;
}
int main(){
    node* root = new node(3);
    root->left = new node(2);
    root->right = new node(1);
    root->left->right = new node(7);
    root->left->right->left = new node(8);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->right = new node(9);

    int start = 2;
    int ans = timeToBurnTree(root,start);
    cout<<ans<<endl;


    return 0;
}
