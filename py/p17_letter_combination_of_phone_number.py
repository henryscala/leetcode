# problem 17 of leetcode
# Letter Combinations of a Phone Number 
class Solution: 
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        self.num2digits=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        return self.letterCombinations1(digits) 

    def letterCombinations1(self, digits):
        result = [] 
        if len(digits) == 1 :
            for char in self.num2digits[ ord(digits[0]) - 0x30 ]:
                result.append(char)
        elif len(digits) <= 0 :
            pass
            #should not reach here
        else:
            for char in self.letterCombinations1(digits[1:]):
                for char2 in self.num2digits[ ord(digits[0]) - 0x30 ]:
                    result.append(char2+char)
        
        return result 

# test
inputStr = "23"
solution = Solution()
result = solution.letterCombinations(inputStr)
print(result)
