'''
23. 合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def mergeKLists(self, lists: List[ListNode]) -> ListNode:
    def mergeKLists(self, lists):
        if len(lists) == 0:
            return None
        elif len(lists) == 1:
            return lists[0]

        if len(lists) >= 3:
            lists[1] = self.mergeKLists(lists[1:])
        
        return self.mergeTwoLists(lists[0], lists[1])

    def mergeTwoLists(self, l1, l2):
        l3 = current = ListNode(0)
        while l1 is not None or l2 is not None:
            if l1 is not None and l2 is not None:
                if l1.val < l2.val:
                    current.next = l1
                    l1 = l1.next
                else:
                    current.next = l2
                    l2 = l2.next
                current = current.next
            elif l1 is not None:
                current.next = l1
                break
            else:
                current.next = l2
                break

        print('=======')
        l_temp = l3.next
        while l_temp is not None:
            print(l_temp.val)
            l_temp = l_temp.next
        return l3.next


if __name__ == '__main__':
    L1 = ListNode(2)
    L2 = None
    L3 = ListNode(-1)

    s = Solution()
    lists = [L1, L2, L3]
    L_merge = s.mergeKLists(lists)
    while L_merge is not None:
        print(L_merge.val)
        L_merge = L_merge.next










