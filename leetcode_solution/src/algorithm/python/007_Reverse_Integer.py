class Solution:
    def reverse(self, x):
    	pos_neg_flag = 1
    	min = -0x80000000
    	max = 0x7fffffff
    	ret = 0
    	if x < 0:
    		pos_neg_flag = 0
    		x = -x
    	while  x != 0:
    		ret *= 10
    		ret += x % 10
    		x //= 10

    	if pos_neg_flag == 0:
    		ret = -ret

    	if min < ret < max:
    		return ret
    	else:
    		return 0