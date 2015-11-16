class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result_map={}
        nums.sort()
        num_elems = len(nums)
        nums_map = {}
        for i,n in enumerate(nums):
            nums_map[n]=i
            

        for i1,e1 in enumerate(nums,0):
            if e1 > 0:
                return list(result_map.values())
            
            for i2 in range(i1+1,num_elems):
                e2 = nums[i2]
                found = False
                e3 = 0 - e1 - e2
                try:
                    index = nums_map[e3]
                    found = True
                except:
                    found = False
                #index,found = self.binary_find(nums, 0 - e1 - e2)
                if found and index > i1 and index > i2:
                    
                    result_map[(e1,e2,e3)]=[e1,e2,e3]
        return list(result_map.values()) 
        
    #nums contains numbers in ascending order    
    def binary_find(self,nums, n):
        num_elems = len(nums)
        ileft = 0
        iright = num_elems - 1

        while iright >= ileft:
            imid = ileft + (iright - ileft)//2
            if nums[imid] == n:
                return imid, True

            if nums[imid] > n:
                iright = imid - 1
            else:
                ileft = imid + 1 
        return -1, False

    
        
        
