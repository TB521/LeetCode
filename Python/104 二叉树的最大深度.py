"""
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

通过次数150,573提交次数207,198
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def maxDepth(self, root):
            """
            :type root: TreeNode
            :rtype: int
            """
            if root is None:
                return 0
            def LDR (root,depth,maxDepth):
                if root == None:
                    return maxDepth
                else:
                    maxDepth = max(depth,maxDepth)
                return max(LDR(root.left,depth + 1,maxDepth),LDR(root.right,depth + 1,maxDepth))
            
        return LDR(root,1,1)