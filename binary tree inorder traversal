# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:        
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        inorder = []
        stack = [root]
        while stack:
            root = stack[-1]
            if root:
                stack.append(root.left)
            else:
                stack.pop()
                if stack:
                    root = stack.pop()
                    inorder.append(root.val)
                    stack.append(root.right)
        return inorder
