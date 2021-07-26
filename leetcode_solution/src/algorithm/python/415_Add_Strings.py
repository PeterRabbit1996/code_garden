'''
415. 字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
'''

class Solution:
    # def addStrings(self, num1: str, num2: str) -> str:
    def addStrings(self, num1, num2):
        if len(num1) > len(num2):
            num1, num2 = num2, num1

        len_num1, len_num2 = len(num1), len(num2)
        carry_num = 0
        str_sum = ''
        for i in range(len_num1):
            sum = 










