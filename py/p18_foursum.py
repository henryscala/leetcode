# problem 18 of leetcode 
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        #print("before sort=", nums) 
        nums = self.sort(nums)
        #print("after sort=", nums) 
        return self.sum(nums, target) 

    # it uses the way to sacrifice space for time 
    def sum(self, nums, target):
        d = dict() 
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                sum2 = nums[i]+nums[j]
                if sum2 in d:
                    d[sum2].append((i,j))
                else:
                    d[sum2]=[(i,j)]

        #print("dict",d) 
        result = []
        for key in d:
            value = target - key
            if value in d:
                list1 = d[key]
                list2 = d[value]
                for (i,j) in list1:
                    for (k,l) in list2:
                        if i != k and i != l and j != k and j != l:
                            num_list = [nums[i],nums[j],nums[k],nums[l]]
                            num_list.sort()
                            result=self.add_to_result(result,num_list)
        return result

    def add_to_result(self, result, nums ):
        for e in result:
            if tuple(e) == tuple(nums):
                return result
        result.append(nums)
        return result
    # this method is useless now 
    def find(self, sorted_nums, target, from_index):
        lo = from_index
        hi = len(sorted_nums) - 1 
        while lo <= hi:
            half = (lo + hi) // 2
            if sorted_nums[half] == target:
                #print("find index",half) 
                return True
            elif sorted_nums[half] > target:
                hi = half - 1
            else:
                lo = half + 1 
        return False
    

    def merge_sorted_array(self,array1, array2):
        result_array = []
        i1 = 0
        i2 = 0
        while i1 < len(array1) and i2 < len(array2):
            if array1[i1] <= array2[i2]:
                result_array.append(array1[i1])
                i1 += 1
            else:
                result_array.append(array2[i2])
                i2 += 1

        if i1 < len(array1):
            result_array.extend(array1[i1:])
        if i2 < len(array2):
            result_array.extend(array2[i2:])
        return result_array 
        
    def sort(self, nums):
        size = len(nums)
        if size <= 1:
            return nums
        half = size // 2
        array1 = nums[0:half]
        array2 = nums[half:]
        #print("sort 1", nums, "array1", array1,"array2", array2) 
        array1 = self.sort(array1)
        array2 = self.sort(array2)
        #print("sort 2", nums, "array1", array1,"array2", array2) 
        result = self.merge_sorted_array( array1, array2 )
        #print("sort 3", "result",result) 
        return result 
        
#test
nums = [1, 0, -1, 0, -2, 2]
target = 0
solution = Solution()
print(solution.fourSum(nums,target)) 
