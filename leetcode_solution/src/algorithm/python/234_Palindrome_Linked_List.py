'''
234. 回文链表

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
'''



# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def isPalindrome(self, head: ListNode) -> bool:
    def isPalindrome(self, head):
        if head == None or head.next == None:
            return True

        p1, p2 = None, None
        pre_slow, slow, fast = head, head, head
        while fast.next != None and fast.next.next != None:
            pre_slow = slow
            slow = slow.next
            fast = fast.next.next
        if fast.next != None:
            fast = fast.next
            p1, p2 = head, slow.next
            slow.next = None
        else:
            slow = pre_slow
            p1, p2 = head, slow.next.next
            slow.next = None

        p1 = self.reverse_list(p1)
        while p1 != None:
            if p1.val != p2.val:
                return False
            #print(p1.val, p2.val)
            p1, p2 = p1.next, p2.next

        return True


    def reverse_list(self, head):
        if head == None or head.next == None:
            return head

        pre, cur = head, head.next
        pre.next = None
        while cur != None:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next

        return pre


if __name__ == '__main__':
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    print(s.isPalindrome(head))




















