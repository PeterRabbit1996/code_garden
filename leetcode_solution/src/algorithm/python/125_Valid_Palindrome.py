'''
125. 验证回文串

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
'''


class Solution:
    # def isPalindrome(self, s: str) -> bool:
    def isPalindrome(self, s):
        if s is None:
            return False

        left, right = 0, len(s) - 1
        while left < right:
            if s[left].isalnum() is False:
                left += 1
                continue
            if s[right].isalnum() is False:
                right -= 1
                continue

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True


if __name__ == '__main__':
    s = Solution()
    # str = "A man, a plan, a canal: Panama"
    str = "race a car"
    print(s.isPalindrome(str))













