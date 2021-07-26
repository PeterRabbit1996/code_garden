class Solution:
	def longestCommonPrefix(self, strs):
		if len(strs) == 0:
			return ""
		elif len(strs) == 1:
			return strs[0]

		common_prefix = ""
		min_len = min(list(map(lambda str: len(str), strs)))
		#print(min_len)
		for i in range(min_len):
			current_char = strs[0][i]
			for j in range(len(strs)):
				if strs[j][i] != current_char:
					return common_prefix
			common_prefix += current_char

		return common_prefix

if __name__ == '__main__':
	strs = ["flower","flow","flight"]
	strs = []
	s = Solution()
	print(s.longestCommonPrefix(strs))