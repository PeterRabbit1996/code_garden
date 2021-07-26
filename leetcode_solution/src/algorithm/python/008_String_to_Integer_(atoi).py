class Solution:
    def myAtoi(self, str):
        min = -0x80000000
        max = 0x7fffffff
        pos_neg_flag = 1
        index = 0
        ret = 0

        while index < len(str) and str[index] == ' ':
        	index += 1

        if index == len(str):
        	return 0
        if str[index] == '+':
        	index += 1
        elif str[index] == '-':
        	index += 1
        	pos_neg_flag = 0;
        #print(str[index:])

        while index < len(str) and ord('0') <= ord(str[index]) <= ord('9'):
        	ret = ret * 10 + int(str[index])
        	index += 1
        #print(ret)

        if ret > 0 and pos_neg_flag == 0:
        	ret = -ret

        if ret < min:
        	return min
        elif ret > max:
        	return max
        else:
        	return ret

if __name__ == '__main__':
	#test_str = "4193 with words"
	#test_str = '123'
	#test_str = ' '
	test_str = "-91283472332"
	s = Solution()
	print(s.myAtoi(test_str))