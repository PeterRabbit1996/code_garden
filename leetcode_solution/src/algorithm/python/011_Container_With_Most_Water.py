class Solution:
	def maxArea(self, height):
		left = 0
		right = len(height) - 1
		#max_v = (len(height) - 1) * min(height[0], height[len(height) - 1])
		max_v = 0
		while left != right:
			v = (right - left) * min(height[left], height[right])
			max_v = max(max_v, v)
			if height[left] < height[right]:
				left += 1
			else:
				right -= 1
		return max_v

if __name__ == '__main__':
	list = [1,8,6,2,5,4,8,3,7]
	s = Solution()
	print(s.maxArea(list))
