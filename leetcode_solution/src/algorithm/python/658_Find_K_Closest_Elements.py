'''
658. 找到 K 个最接近的元素

给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

示例 1:

输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
 

示例 2:

输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
 

说明:

k 的值为正数，且总是小于给定排序数组的长度。
数组不为空，且长度不超过 10^4
数组里的每个元素与 x 的绝对值不超过 10^4
 

更新(2017/9/19):
这个参数 arr 已经被改变为一个整数数组（而不是整数列表）。 请重新加载代码定义以获取最新更改。
'''


'''
NOT FINISHED
'''
class Solution:
    # def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
    def findClosestElements(self, arr, k, x):
        '''
        res = 0
        max_abs = max(abs(arr[0] - x), abs(arr[k - 1] - x)) + 1
        for i in range(len(arr) - k):
            print(max(abs(arr[i] - x), abs(arr[i + k - 1] - x)))
            if max(abs(arr[i] - x), abs(arr[i + k - 1] - x)) >= max_abs:
                if i != 0:
                    res -= 1
                break

        return arr[res: res + k]
        '''

        
        if len(arr) == k:
            return arr

        max_list = []
        for i in range(len(arr) - k + 1):
            max_list.append(max(abs(arr[i] - x), abs(arr[i + k - 1] - x)))
        print(max_list)
        index = max_list.index(min(max_list))

        return arr[index: index + k]


if __name__ == '__main__':
    # arr = [0, 0, 1, 2, 3, 3, 4, 7, 7, 8]
    # k = 3
    # x = 5

    # arr = [1]
    # k = 1
    # x = 1

    arr = [0,1,2,2,2,3,6,8,8,9]
    k = 5
    x = 9

    s = Solution()
    print(s.findClosestElements(arr, k, x))



















