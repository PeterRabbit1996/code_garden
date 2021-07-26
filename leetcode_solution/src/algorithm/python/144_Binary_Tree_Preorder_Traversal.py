'''
144. 二叉树的前序遍历


给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # def preorderTraversal(self, root: TreeNode) -> List[int]:
    def preorderTraversal(self, root):
        if root == None:
            return []

        stack, result = [root, ], []
        while stack:
            cur = stack.pop()
            if cur != None:
                result.append(cur.val)
                if cur.right != None:
                    stack.append(cur.right)
                if cur.left != None:
                    stack.append(cur.left)

        return result

















