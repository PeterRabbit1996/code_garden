class Solution:
#	def twoSum(self, nums: List[int], target: int) -> List[int]:
	def twoSum(self, nums, target):
		result = []
		list.sort(nums)
		low = 0
		high = len(nums) - 1

		while low < high:
			if low != 0 and nums[low - 1] == nums[low]:
				low += 1
				continue
			current_sum = nums[low] + nums[high]
			if current_sum == target:
				result += [[nums[low], nums[high]]]
				low += 1
				high -= 1
			elif current_sum < target:
				low += 1
			else:
				high -= 1
		return result

#	def threeSum(self, nums: List[int]) -> List[List[int]]:
	def threeSum(self, nums):
		result = []
		list.sort(nums)
		if len(nums) <= 2 or nums[0] > 0 or nums[len(nums) - 1] < 0:
			return []

		for i in range(len(nums) - 2):
			if nums[i - 1] == nums[i] and i != 0:
				continue
			list_twoSum = self.twoSum(nums[i + 1:], -nums[i])
			if len(list_twoSum) == 0:
				continue
			for j in range(len(list_twoSum)):
				result += [[nums[i]] + list_twoSum[j]]
		return result

if __name__ == '__main__':
#	nums = [-1, 0, 1, 2, -1, -4]
#	nums = []
	nums = [-2,0,0,2,2]
	s = Solution()
	print(s.threeSum(nums))