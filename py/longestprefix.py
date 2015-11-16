# -*- coding: utf-8 -*-
# problem 14 of leet code 
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        num_rows = len(strs)
        if num_rows <= 0:
            return ''
            
        column = 0 
        end = False
        while True:
            c = None
            
            for row in range(num_rows):
                try:
                    if not c: 
                        c = strs[row][column]
                    else:
                        c2 = strs[row][column]
                        if c2!=c:
                            end = True 
                            break 
                except IndexError: 
                    end = True 
            if not end:        
                column += 1 
            else:
                break
            
        
        
        return strs[0][0:column]
        
    def test(self): 
        strs = ["abc", "abcd","abcde"]
        assert self.longestCommonPrefix(strs) == 'abc' 
        strs = []
        assert self.longestCommonPrefix(strs) == ''
        
        strs = ["a","b"]
        assert self.longestCommonPrefix(strs) == ''
                        
            
                
            
            