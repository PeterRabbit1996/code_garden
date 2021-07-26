'''
102. 二叉树的层序遍历

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # def levelOrder(self, root: TreeNode) -> List[List[int]]:
    def levelOrder(self, root):
        if root == None:
            return []
            
        ans = []
        list_val = []
        list_cur = [root]
        list_next = []

        while True:
            for node in list_cur:
                list_val.append(node.val)

                if node.left != None:
                    list_next.append(node.left)
                if node.right != None:
                    list_next.append(node.right)
            ans.append(list_val)
            
            if len(list_next) == 0:
                break
            
            list_val = []
            list_cur = list_next
            list_next = []

        return ans














