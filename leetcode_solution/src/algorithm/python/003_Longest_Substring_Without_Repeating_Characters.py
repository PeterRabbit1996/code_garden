'''
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
'''


class Solution:
    # def lengthOfLongestSubstring(self, s: str) -> int:
    def lengthOfLongestSubstring(self, s):
        s_len = len(s)
        cur_len, max_len = 0, 0
        left_index, right_index = 0, 0
        cur_set = set()
        for i in range(s_len):
            if s[i] not in cur_set:
                cur_set.add(s[i])
                right_index += 1
                cur_len += 1
                if cur_len > max_len:
                    max_len = cur_len
                continue

            while s[left_index] != s[i]:
                cur_set.remove(s[left_index])
                left_index += 1
                cur_len -= 1
            left_index += 1

        return max_len


if __name__ == '__main__':
    str = 'abcabcbb'
    # str = 'bbbbbbbb'
    # str = 'pwwkew'
    # str = ''
    s = Solution()
    print(s.lengthOfLongestSubstring(str))











