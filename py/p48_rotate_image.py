# problem 48 of leetcode,
# rotate image 90 degree clockwise 
class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        self.reflect_diagnal(matrix)
        self.reflect_vertical(matrix) 
        
    def reflect_diagnal(self,matrix):
        n = len(matrix) 
        for row in range(0,n-1):
            for col in range(0,n-1-row):
                opposite_row = n-1-col
                opposite_col = n-1-row
                matrix[row][col],matrix[opposite_row][opposite_col] = \
                    matrix[opposite_row][opposite_col] ,matrix[row][col]
                
    def reflect_vertical(self,matrix):
        n = len(matrix) 
        for row in range(0,n//2):
            new_row = n - row - 1
            for col in range(0,n):
                matrix[row][col],matrix[new_row][col] = \
                      matrix[new_row][col] , matrix[row][col]
        
m = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
solution = Solution()
solution.rotate(m)
print(m)

