class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = [] 
        if numRows == 0:
            return result 
        row = [1] 
        result.append(row)
        if numRows == 1: 
            return result

        for i in range(1,numRows):
            nextrow=[1] 
            for k in range(1,len(row)): 
                nextrow.append(row[k-1]+row[k]) 
            nextrow.append(1) 
            row=nextrow 
            result.append(row) 
        return result 


s=Solution() 
print(s.generate(5)) 
print(s.generate(0)) 
print(s.generate(1)) 
print(s.generate(2)) 



