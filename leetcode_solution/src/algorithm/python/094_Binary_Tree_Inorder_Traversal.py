'''
94. 二叉树的中序遍历

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
'''


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # def inorderTraversal(self, root: TreeNode) -> List[int]:
    def inorderTraversal(self, root):        
        remain, result, cur = [], [], root

        while cur is not None or len(remain) != 0:
            while cur is not None:
                remain.insert(0, cur)
                cur = cur.left

            cur = remain.pop(0)
            result.append(cur.val)
            cur = cur.right

        return result


            












