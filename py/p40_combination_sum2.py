# problem 40 of leetcode 
class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result = self.combinationSum1(candidates,target,0)
        # remove duplicates
        result_set = set()
        for l in result:
            result_set.add(tuple(l))
        final_result = [ list(l) for l in result_set ]
        return final_result 
        
    def combinationSum1(self, candidates, target, minIndex):
        result = []
        for i in range(minIndex,len(candidates)):
            if candidates[i] == target:
                result.append([candidates[i]])
                break
            elif candidates[i] > target:
                break 
            else:
                
                sub_result_list = self.combinationSum1(candidates, target-candidates[i],i+1)
                for sub_result in sub_result_list:
                    sub_result.insert(0,candidates[i])
                    result.append(sub_result)
        return result 

# testing codes
print("case1")
candidates = [10,1,2,7,6,1,5]
solution = Solution()
result = solution.combinationSum2(candidates,8)
print(result)

print("case2") 
candidates = [2,5,2,1,2]
result = solution.combinationSum2(candidates,5)
print(result)



