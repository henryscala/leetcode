# problem 16 of leetcode
# three number's sum closest to the target 
class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        two_sums = dict() #map from two number's sum and the index list of the pairs 
        minVal = None
        maxVal = None
        for i,e in enumerate(nums):
            # remember the minimum value in the array 
##            if minVal == None: 
##                minVal = e 
##            elif minVal > e: 
##                minVal = e  
            # remember the maximum value in the array 
##            if maxVal == None: 
##                maxVal = e 
##            elif maxVal < e: 
##                maxVal = e 

            for i2 in range(i+1,len(nums)):
                e2 = nums[i2]
                two_sum = e2 + e
                if two_sum in two_sums:
                    two_sums[two_sum].add((i,i2))
                else:
                    two_sums[two_sum] = {(i,i2)} # the value is a set of tuples 
                
        
        closest =  nums[0] + nums[1] + nums[2]  

        for twoSum,indices in two_sums.items(): 
            for i,e in enumerate(nums):
                threeSum = twoSum + e
                if abs(threeSum - target) <= abs(closest-target):
                    for pairs in indices:
                        if pairs[0] != i and pairs[1] != i : 
                            closest = threeSum
                            break 
        
        return closest 

solution = Solution()

nums = [-1, 2, 1, -4]
target = 1
print(solution.threeSumClosest(nums, target))

nums = [0,0,0]
target = 1
print(solution.threeSumClosest(nums, target)) 
