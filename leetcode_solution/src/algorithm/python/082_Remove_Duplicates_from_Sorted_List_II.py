'''
82. 删除排序链表中的重复元素 II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def deleteDuplicates(self, head: ListNode) -> ListNode:
    def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head

        p1 = ListNode(0)
        p1.next, p2 = head, head
        head = p1
        while p2 != None and p2.next != None:
            if p2.val != p2.next.val:
                p1, p2 = p1.next, p2.next
                continue

            val = p1.next.val
            while p2.val == val:
                p1.next = p2.next
                p2 = p2.next

                if p2 == None:
                    break


        return head.next


if __name__ == '__main__':
    pass









