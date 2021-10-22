/***********PROBLEM STATEMENT*************
Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

Example:
     1                  1
      \                  \
       0          ->      0 
      / \                  \
     0   1                  1

Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Link: https://leetcode.com/problems/binary-tree-pruning
/*****************************************/

class Solution {
public:
    
    bool helper(TreeNode* root) {
        if(root==NULL) {
            return false;
        }
        //calls recursion for both left and right subtrees
        bool rightHas1 = helper(root->right);
        bool leftHas1 = helper(root->left);

        //Make the subtree without 0 into NULL
        if(rightHas1 == false) {
            root->right = NULL;
        } 
        if(leftHas1 == false) {
            root->left = NULL;
        }
        if(root->val == 1) 
            return true;
        
        return rightHas1 || leftHas1; 
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) {
           return root;
        }
        bool has1 = helper(root);
        if(has1==false)
            root = nullptr;
        
        return root;
        
    }
};

//This solution is written by Parth Jaiswal (https://github.com/parth-jaiswal)