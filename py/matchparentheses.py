class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        lpairs={'(':')', '[':']', '{':'}' }
        rpairs={}
        for k,v in lpairs.items():            
            rpairs[v]=k
            
        for c in s:
            
            try:
                #c is a left parenthesis 
                right_paren = lpairs[c]
                stack.append(c)
                continue
            except:
                pass

            try:
                #c is a right parenthesis 
                left_paren = rpairs[c]
                if len(stack) == 0:
                    return False 
                top_paren = stack.pop()
                if top_paren != left_paren:
                    return False 
            except:
                pass 

        if len(stack) != 0:
            return False

        return True 

    def test(self):
        assert self.isValid("a(b+c)") == True
        assert self.isValid("a[b+c)") == False 
            
            
