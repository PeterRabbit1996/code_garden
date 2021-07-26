class Solution:
	def isPalindrome(self, x):
		if x < 0:
			return False

		x_copy = x
		x_reverse = 0
		while x_copy != 0:
			x_reverse = x_reverse * 10 + x_copy % 10
			x_copy //= 10

		if x == x_reverse:
			return True
		else:
			return False