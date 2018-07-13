# problem 39 of leetcode 
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        return self.combinationSum1(candidates,target,0) 
        
    def combinationSum1(self, candidates, target, minIndex):
        result = []
        for i in range(minIndex,len(candidates)):
            if candidates[i] == target:
                result.append([candidates[i]])
                break
            elif candidates[i] > target:
                break 
            else:
                
                sub_result_list = self.combinationSum1(candidates, target-candidates[i],i)
                for sub_result in sub_result_list:
                    sub_result.insert(0,candidates[i])
                    result.append(sub_result)
        return result 

# testing codes
print("case1")
candidates = [2,3,6,7]
solution = Solution()
result = solution.combinationSum(candidates,7)
print(result)

print("case2") 
candidates = [2,3,5]
result = solution.combinationSum(candidates,8)
print(result)



