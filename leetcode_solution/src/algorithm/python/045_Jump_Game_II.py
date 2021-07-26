'''
45. 跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
'''

class Solution:
    # def jump(self, nums: List[int]) -> int:
    def jump(self, nums):
        steps = 0
        pos_left, pos_right = 0, 1

        while pos_right < len(nums):
            max_steps = 0
            while pos_left < pos_right:
                max_steps = max(max_steps, pos_left + nums[pos_left])
                pos_left += 1
            
            pos_left = pos_right
            pos_right = max_steps + 1
            steps += 1

        return steps

if __name__ == '__main__':
    nums = [2, 3, 1, 1, 4, 2, 1]
    s = Solution()
    print(s.jump(nums))

















