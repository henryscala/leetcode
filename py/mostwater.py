#leetcode problem 11
#container with most water 
#this should be a greedy algorithm 
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0 
        low = 0 
        high = len(height)-1 
        
        while low < high:
            area = (high - low)*min(height[low],height[high]) 
            if area > max_area:
                max_area = area 
            if height[low]<=height[high]:
                low += 1
            else:
                high -= 1
        return max_area   
    
        
        
        