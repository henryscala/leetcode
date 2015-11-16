#import pdb 
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False 
        n = self.numDigits(x)
        #pdb.set_trace() 

        while n > 1:
            
            head,x,tail = self.trimBorderDigit(x, n)
            #print("head",head,"tail",tail) 
            if (head != tail):
                return False
            
            #print("x",x)
            n -= 2
        return True     
        
    def numDigits(self,x):
        d = 0
        if x == 0:
            return 1
        
        while x != 0:
            x = x // 10
            d += 1
        return d

 

    def trimBorderDigit(self,x,numDigits):
        assert (numDigits>=2)
        v = 10**(numDigits-1)
        firstDigit = x // v
        x -=  firstDigit*v
        lastDigit = x % 10
        x = x // 10
        return firstDigit, x, lastDigit
