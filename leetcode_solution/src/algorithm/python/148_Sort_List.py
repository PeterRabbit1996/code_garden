'''
148. 排序链表

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def sortList(self, head: ListNode) -> ListNode:
    def sortList(self, head: ListNode) -> ListNode:
        cur_ptr = head
        list_num = []
        while cur_ptr != None:
            list_num.append(cur_ptr.val)
            cur_ptr = cur_ptr.next

        list.sort(list_num)
        cur_ptr = head
        for i in range(len(list_num)):
            cur_ptr.val = list_num[i]
            cur_ptr = cur_ptr.next

        return head


if __name__ == '__main__':
    head = ListNode(5)
    head.next = ListNode(8)
    head.next.next = ListNode(6)
    head.next.next.next = ListNode(2)
    head.next.next.next.next = ListNode(7)

    s = Solution()
    result = s.sortList(head)
    while result != None:
        print(result.val)
        result = result.next