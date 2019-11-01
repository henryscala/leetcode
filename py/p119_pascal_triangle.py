class Solution:
    def getRow(self, rowIndex):
        row  = [] 
        if rowIndex < 0 or rowIndex > 33 : 
            return row 
        row = [1] 
        
        for i in range(1,rowIndex+1):
            nextrow=[1] 
            for k in range(1,len(row)): 
                nextrow.append(row[k-1]+row[k]) 
            nextrow.append(1) 
            row=nextrow 
        return row  


s=Solution() 
print(s.getRow(3)) 
print(s.getRow(0)) 
print(s.getRow(1)) 
print(s.getRow(2)) 



