/* PROBLEM STATEMENT : Given the root of a binary tree, invert the tree, and return its root.
   SAMPLE TEST CASES :
   Input: root = [4,2,7,1,3,6,9]
   Output: [4,7,2,9,6,3,1]
   
   Input: root = [2,1,3]
   Output: [2,3,1]
   
   Input: root = []
   Output: []
*/


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;
class Solution {
    public TreeNode invertTree(TreeNode root) {
        
        if(root==null)
            return null;
        
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        q.add(root);
        
        while(!q.isEmpty())
        {
            TreeNode curr = q.poll();
          
          //Swapping of left and right node of tree
            TreeNode temp = curr.left;
            curr.left = curr.right;
            curr.right = temp;
            
            if (curr.left != null)
            q.add(curr.left);
        	  if (curr.right != null)
            q.add(curr.right);
            
        }
        
        return root;
    }
}
