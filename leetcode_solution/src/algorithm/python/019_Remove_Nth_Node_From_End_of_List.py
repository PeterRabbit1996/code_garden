#给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
#示例：
#给定一个链表: 1->2->3->4->5, 和 n = 2.
#当删除了倒数第二个节点后，链表变为 1->2->3->5.
#说明：
#给定的 n 保证是有效的。
#进阶：
#你能尝试使用一趟扫描实现吗？

#Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
#	def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
	def removeNthFromEnd(self, head, n):
		if head == None:
			return None
		back, front = head, head
		for i in range(n):
			front = front.next
		if front == None:
			head = head.next
			return head
		while front.next != None:
			back = back.next
			front = front.next
		back.next = back.next.next

		return head

if __name__ == '__main__':
	head = ListNode(1)
	head.next = ListNode(2)
	head.next.next = ListNode(3)
	head.next.next.next = ListNode(4)
	s = Solution()
	s.removeNthFromEnd(head, 2)
	print(head.val)
	print(head.next.val)
	print(head.next.next.val)
