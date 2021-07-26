class Solution:
    def twoSum(self, nums, target):
        num_index = [(num, index) for index, num in enumerate(nums)]
        num_index.sort()
        low, high = 0, len(nums) - 1
        
        while low < high:
            current_sum = num_index[low][0] + num_index[high][0]
            if current_sum == target:
                return [num_index[low][1], num_index[high][1]]
            elif current_sum < target:
                low += 1
            else:
                high -= 1

if __name__ == '__main__':
    list_num = [2, 7, 11, 15]
    s = Solution()
    print(s.twoSum(list_num, 9))