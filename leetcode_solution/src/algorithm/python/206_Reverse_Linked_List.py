'''
206. 反转链表

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def reverseList(self, head: ListNode) -> ListNode:
    def reverseList(self, head):
        if head == None or head.next == None:
            return head

        p1 = head
        p2 = head.next
        p1.next = None
        while p2.next != None:
            p3 = p2.next
            p2.next = p1
            p1 = p3.next
            p1, p2 = p2, p1
            p2 = p3
        p2.next = p1

        return p2

if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    s = Solution()
    s.reverseList(head)










