class Solution:
#	def letterCombinations(self, digits: str) -> List[str]:
	def letterCombinations(self, digits):
		map_digits_letter = {
							"2": "abc",
							"3": "def",
							"4": "ghi",
							"5": "jkl",
							"6": "mno",
							"7": "pqrs",
							"8": "tuv",
							"9": "wxyz"
							}

		if len(digits) == 0:
			return []
		elif len(digits) == 1:
			return list(map_digits_letter[digits[0]])
		current_digit_letter_list = list(map_digits_letter[digits[0]])
		#print(current_digit_letter_list)
		result = []
		for i in range(len(current_digit_letter_list)):
			#map(lambda str: result[i] =+ str, self.letterCombinations(digits[1:]))
			for str in self.letterCombinations(digits[1:]):
				result += [current_digit_letter_list[i] + str]

		return result

if __name__ == '__main__':
	digits = "23"
	s = Solution()
	print(s.letterCombinations(digits))
