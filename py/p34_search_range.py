# problem 34 of leetcode 
# Find First and Last Position of Element in Sorted Array
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        found,low,high = self.search(nums, 0, len(nums)-1,target)
        if found:
            return [low,high]
        return [-1,-1]
    
    def search(self, nums, fromIndex, toIndex, target):
        if fromIndex > toIndex:
            return False,-1,-1
        
        half = (fromIndex + toIndex) // 2
        if nums[half] > target:
            return self.search(nums, fromIndex, half-1,target)
        elif nums[half] < target:
            return self.search(nums, half+1, toIndex, target)

        interval = [ half, half ] 
        found,low,high = self.search(nums, fromIndex, half-1,target)
        if found:
            interval[0] = low

        found,low,high = self.search(nums, half+1, toIndex,target)
        if found:
            interval[1] = high
            
        return True, interval[0], interval[1]
        
nums = [5,7,7,8,8,10]
target = 8
solution = Solution()
print(solution.searchRange(nums,target))

nums = [5,7,7,8,8,10]
target = 6
print(solution.searchRange(nums,target))

