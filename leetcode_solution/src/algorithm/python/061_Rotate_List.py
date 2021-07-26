'''
61. 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def rotateRight(self, head: ListNode, k: int) -> ListNode:
    def rotateRight(self, head, k):
        if head == None:
            return head
        elif head.next == None:
            return head

        len_list = 0
        tmp_cur = head
        while tmp_cur != None:
            tmp_cur = tmp_cur.next
            len_list += 1

        left, right = head, head
        for i in range(k % len_list):
            if right == None:
                right = head
            right = right.next
        # print(right.val)

        if right == None or right == head:
            return head


        while right.next != None:
            left = left.next
            right = right.next
        # print(left.val)

        right.next, right, left.next = head, left.next, None

        return right

if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    s = Solution()
    res = s.rotateRight(head, 2200001)

    while res != None:
        print(res.val)
        res = res.next













