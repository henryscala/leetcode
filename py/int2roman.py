#problem 12&13: integer to roman and to integer
class Solution(object):

    def __init__(self):
        self.all_roman_char = 'IVXLCDM'

        self.char_value = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
            }

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        stack=[] #length of stack cannot exceed 2 
        result=0
        for c in s:
            if len(stack)==0:
                stack.append(c)
            else:
                currValue=self.char_value[c]
                valueInStack=self.char_value[stack[0]]
                if valueInStack >= currValue: #correct sequence
                    result += valueInStack
                    stack[0]=c
                else: #in corect sequence, means IV, or IX, or CD, etc encountered
                    result += currValue-valueInStack
                    stack=[]
        if len(stack)>0:
            result += self.char_value[stack[0]]
           
        return result     
    
        
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        
        i=len(self.all_roman_char)-1
        result = ""

        
        while i>=0:
            times = 0
            char = self.all_roman_char[i]
            value = self.char_value[char]                        
            
            
            times = num // value

            if times > 0:
                num = num - times * value 
            
            
                
            if times>=4:
                prevChar = self.all_roman_char[i+1]
                prevPrevChar = self.all_roman_char[i+1+1]
                if len(result)>0 :
                    lastCharInResult=result[-1]
                    if lastCharInResult==prevChar:
                        result = result[0:len(result)-1]
                        result += char + prevPrevChar
                    else:
                        result += char + prevChar
                else:        
                    result += char + prevChar
                
                
                
            else:
                result += char * times 
        
                            
            i -= 1
            
            
            
        
        return result      
                

if '__main__' == __name__:
    print ("executing")
    s=Solution()
    assert s.intToRoman(100) == 'C'
    
    assert s.intToRoman(201) == 'CCI'
    
    assert s.intToRoman(401) == 'CDI'
    assert s.intToRoman(9) == 'IX'

    assert s.romanToInt( s.intToRoman(100) )== 100
    
    assert s.romanToInt( s.intToRoman(201) ) == 201
    
    assert s.romanToInt( s.intToRoman(401) ) == 401 
    assert s.romanToInt( s.intToRoman(9) ) == 9 
    print ("done.") 
        
