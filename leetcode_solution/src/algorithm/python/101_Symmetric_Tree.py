'''
101. 对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # def isSymmetric(self, root: TreeNode) -> bool:
    def isSymmetric(self, root):
        if root == None:
            return True
        return self.isMirror(root.left, root.right)
        

    def isMirror(self, t_1, t_2):
        if t_1 == None and t_2 == None:
            return True
        if t_1 == None or t_2 == None:
            return False

        # return t_1.val == t_2.val and self.isMirror(t_1.left, t_2.right) == True and self.isMirror(t_1.right, t_1.left) == True

        if t_1.val == t_2.val:
            return self.isMirror(t_1.left, t_2.right) and self.isMirror(t_1.right, t_2.left)























