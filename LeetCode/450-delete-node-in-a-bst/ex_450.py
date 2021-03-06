# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:    return
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.right: return root.left
            if not root.left:  return root.right
            temp = root
            root = self.minNode(temp.right)
            root.right = self.deleteMin(temp.right)
            root.left = temp.left
        return root
        
    def minNode(self, node):
        while node.left:
            node = node.left
        return node
        
    def deleteMin(self, node):
        if not node.left:   return node.right
        node.left = self.deleteMin(node.left)
        return node