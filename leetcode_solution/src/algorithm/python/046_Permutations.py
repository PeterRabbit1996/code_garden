'''
46. 全排列

给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
'''


class Solution:
    # def permute(self, nums: List[int]) -> List[List[int]]:
    def permute(self, nums):
        if nums == None:
            return None
        elif len(nums) <= 1:
            return [nums]

        result = []
        for i in range(len(nums)):
            for val in self.permute(nums[0: i] + nums[i + 1: ]):
                result.append(val + [nums[i]])

        return result


if __name__ == '__main__':
    nums = []
    # nums = [1, 2, 3, 4]
    s = Solution()
    print(s.permute(nums))














