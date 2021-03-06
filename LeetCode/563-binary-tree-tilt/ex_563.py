# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    s = 0
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.s = 0
        self.helper(root)
        return self.s
        
    def helper(self, node):
        if not node:    return 0
        l = self.helper(node.left)
        r = self.helper(node.right)
        self.s += abs(l - r)
        return l + r + node.val
        