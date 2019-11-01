# problem 75 of leetcode 
class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        leftindex = 0
        rightindex = len(nums)-1
        while leftindex < rightindex:
            while leftindex < rightindex and nums[leftindex] == 0:
                leftindex += 1
            while leftindex < rightindex and nums[rightindex] != 0:
                rightindex -= 1
            if leftindex < rightindex:
                tmp = nums[leftindex]
                nums[leftindex] = nums[rightindex]
                nums[rightindex] = tmp
                leftindex += 1
                rightindex -= 1 

        #after the above steps, all 0s are in the correct positions,
        #and leftindex is correct
        #after the below steps, all 1s and 2s are in the correct positions, too
        #print("middle",leftindex,rightindex,nums)         
        rightindex = len(nums)-1
        while leftindex < rightindex:
            while leftindex < rightindex and nums[leftindex] != 2:
                leftindex += 1
            while leftindex < rightindex and nums[rightindex] == 2:
                rightindex -= 1
            if leftindex < rightindex:
                tmp = nums[leftindex]
                nums[leftindex] = nums[rightindex]
                nums[rightindex] = tmp
                leftindex += 1
                rightindex -= 1 


if __name__ == '__main__':
    a = [1,2,0,1,0,2] 
    s = Solution()
    s.sortColors(a)
    print(a)

    a = [1,0,0]
    s.sortColors(a)
    print(a)

    a = [2,0,0]
    s.sortColors(a)
    print(a)

    a = [2,1,1]
    s.sortColors(a)
    print(a) 
    
        
