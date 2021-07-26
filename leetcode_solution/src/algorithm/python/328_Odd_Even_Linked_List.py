'''
328. 奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def oddEvenList(self, head: ListNode) -> ListNode:
    def oddEvenList(self, head):
        if head == None or head.next == None:
            return head

        root_odd, root_even = head, head.next
        cur_left, cur_right = root_odd, root_even
        while True:
            if cur_right.next == None:
                break
            cur_left.next = cur_right.next
            cur_left = cur_left.next

            if cur_left.next == None:
                cur_right.next = None
                break
            cur_right.next = cur_left.next
            cur_right = cur_right.next

        cur_left.next = root_even

        return root_odd


if __name__ == '__main__':
    head = ListNode(0)
    cur_ptr = head
    end_num = 10
    for i in range(1, end_num):
        cur_ptr.val = i
        cur_ptr.next = ListNode(0)
        if i == end_num - 1:
            cur_ptr.next = None
        cur_ptr = cur_ptr.next

    # cur_ptr = head
    # while cur_ptr != None:
    #     print(cur_ptr.val)
    #     cur_ptr = cur_ptr.next

    s = Solution()
    result = s.oddEvenList(head)
    while result != None:
        print(result.val)
        result = result.next













