'''
48. 旋转图像

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
'''


class Solution:
    # def rotate(self, matrix: List[List[int]]) -> None:
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(int(len(matrix) / 2 + 1)):
            n = len(matrix)
            up_i , up_j = i, i
            right_i, right_j = i, n - 1 - i
            down_i, down_j = n - 1 - i, n - 1 - i
            left_i, left_j = n - 1 - i, i

            for j in range(len(matrix[0]) - 1 - 2 * i):
                # print(up_i, up_j)
                # print(matrix[up_i][up_j], matrix[right_i][right_j], matrix[down_i][down_j], matrix[left_i][left_j])
                matrix[up_i][up_j], matrix[right_i][right_j], matrix[down_i][down_j], matrix[left_i][left_j] = \
                    matrix[left_i][left_j], matrix[up_i][up_j], matrix[right_i][right_j], matrix[down_i][down_j]
                
                up_j += 1
                right_i += 1
                down_j -= 1
                left_i -= 1


if __name__ == '__main__':
    s = Solution()
    matrix = [
               [1, 2, 3, 4],
               [5, 6, 7, 8],
               [9, 10, 11, 12],
               [13, 14, 15, 16]
             ]
    s.rotate(matrix)
    # print(matrix)













