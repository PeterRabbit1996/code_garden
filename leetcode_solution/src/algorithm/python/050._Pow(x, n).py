'''
50. Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
'''


class Solution:
    # def myPow(self, x: float, n: int) -> float:
    def myPow(self, x, n):
        if x == 0:
            return 0

        if n == 0 :
            return 1
        elif n == 1:
            return x

        if n < 0:
            n = -n
            x = 1 / x

        sum = 1
        # for i in range(n):
        #     sum *= x
        if n % 2 == 0:
            # print('n = ', n)
            sum *= self.myPow(x * x, n // 2)
        else:
            # print('n = ', n)
            sum *= x * self.myPow(x * x, n // 2)

        return sum

if __name__ == '__main__':
    s = Solution()
    print(s.myPow(2, 9))








