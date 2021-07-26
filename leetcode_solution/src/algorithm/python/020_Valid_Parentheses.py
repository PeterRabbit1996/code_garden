'''
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true
'''

class Solution:
#	def isValid(self, s: str) -> bool:
	def isValid(self, s):
		stack_brackets = []
		for i in range(len(s)):
			if s[i] == '{' or s[i] == "[" or s[i] == "(":
				stack_brackets.append(s[i])
			else:
				try:
					left_brackets = stack_brackets.pop()
				except Exception as e:
					return False
				if left_brackets == "{" and s[i] != "}":
					return False
				elif left_brackets == "[" and s[i] != "]":
					return False
				elif left_brackets == "(" and s[i] != ')':
					return False

		if len(stack_brackets) == 0:
			return True
		else:
			return False

if __name__ == '__main__':
	str = "{}[]()"
	s = Solution()
	print(s.isValid(str))