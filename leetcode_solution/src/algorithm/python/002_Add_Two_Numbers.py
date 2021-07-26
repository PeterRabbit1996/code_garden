# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        current = result_head = ListNode(0)
        while l1 or l2:
            if l1:
                current.val += l1.val
                l1 = l1.next
            if l2:
                current.val += l2.val
                l2 = l2.next
            current.next = ListNode(current.val // 10)
            current.val = current.val % 10
            if l1 is None and l2 is None and current.next.val is 0:
                current.next = None
                continue
            current = current.next

        return result_head

if __name__ == '__main__':
    s = Solution()
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    l3 = s.addTwoNumbers(l1, l2)

    while l3:
        print(l3.val, end = " ")
        l3 = l3.next