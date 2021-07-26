'''
725. 分隔链表

给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：

输入: 
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
示例 2：

输入: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 

提示:

root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
    def splitListToParts(self, root, k):
        len_root = 0
        cur_ptr = root
        list_node = []
        while cur_ptr != None:
            list_node.append(ListNode(cur_ptr.val))
            len_root += 1
            cur_ptr = cur_ptr.next

        quotient = len_root // k
        remainder = len_root % k
        # print('len_root', len_root)
        # print('quotient', quotient)
        # print('remainder', remainder)
        
        index = 0
        result = []
        for i in range(remainder):
            sub_result = list_node[index]
            result.append(sub_result)
            index += 1

            for j in range(quotient):
                sub_result.next = list_node[index]
                sub_result = sub_result.next
                index += 1
        for i in range(k - remainder):
            if len_root < k:
                result.append(None)
                continue
            sub_result = list_node[index]
            result.append(sub_result)
            index += 1
            for j in range(quotient - 1):
                sub_result.next = list_node[index]
                sub_result = sub_result.next
                index += 1

        # for i in range(remainder):
        #     sub_result = ListNode(cur_ptr.val)
        #     result.append(sub_result)

        #     for j in range(quotient + 1):
        #         sub_result.val = cur_ptr.val
        #         sub_result.next = ListNode(0)
        #         # cur_ptr = cur_ptr.next
        #         # sub_result.next = ListNode(cur_ptr.val)
        #         # sub_result = sub_result.next
        # for i in range(k - remainder):
        #     if len_root < k:
        #         result.append(None)
        #         continue

        #     sub_result = ListNode(cur_ptr.val)
        #     result.append(sub_result)

        #     for j in range(quotient - 1):
        #         cur_ptr = cur_ptr.next
        #         sub_result.next = ListNode(cur_ptr.val)
        #         sub_result = sub_result.next

        return result


if __name__ == '__main__':
    root = ListNode(0)
    k = 6
    cur_ptr = root
    for i in range(1, 6):
        cur_ptr.val = i
        cur_ptr.next = ListNode(0)
        if i == 5:
            break
        cur_ptr = cur_ptr.next
    cur_ptr.next = None

    s = Solution()
    result = s.splitListToParts(root, k)

    print('==============================')
    for i in range(len(result)):
        cur_ptr = result[i]
        while cur_ptr != None:
            print(cur_ptr.val)
            cur_ptr = cur_ptr.next
















