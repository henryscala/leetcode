# -*- coding: utf-8 -*-
# problem 10 of leet code on regular expression matching 
class Solution(object):
    ANY_CHAR = -1
    EXACT_CHAR = 1
    ZERO_OR_MORE = -1
    def isMatch(self, input_str, rule_str):
        """
        :type input_str: str
        :type rule_str: str
        :rtype: bool
        """
        rule_list = self.parseRule(rule_str)
#        if not rule_list:#empty
#            if not input_str:
#                return True
#            else:
#                return False 
        count_input = len(input_str)
        count_rule = len(rule_list)
        i_rule = 0 
        i_input = 0 
        while i_input<count_input:
            char = input_str[i_input]
            i_rule,ok=self.transitState(rule_list, i_rule, char)
            if not ok:
                return False
            
            i_input += 1 
            if i_rule>=count_rule:
                break 
         
        if i_input == count_input:
            if i_rule == count_rule:
                return True
            else : 
                for r in range(i_rule,count_rule): 
                    if rule_list[r][2] != self.ZERO_OR_MORE:
                        return False
                return True
        else:
            return False 
            
    
    def transitState(self, rule_list,rule_index, char): 
        if rule_index>=len(rule_list):
            return -1, False 
        rule = rule_list[rule_index]
        char_type,match_char,cardinal = rule
        matched=False 
        
        if char_type == self.ANY_CHAR:
            matched=True
        elif char_type == self.EXACT_CHAR:
            if char == match_char:
                matched=True
        if matched:
            if cardinal == self.ZERO_OR_MORE :
                return rule_index, True 
            else:
                return rule_index+1, True
        else:
            if cardinal == self.ZERO_OR_MORE :      
                   
                return self.transitState(rule_list,rule_index+1,char) #recursive 
            else:
                return -1, False 
        
    #some rules are left recursive, for example "a*a", change it to right recursive aa* 
    #some rules are redundant, for example "a*.*", change it to ".*" 
    def eliminateRule(self,rule_list):
        pass
        
    def parseRule(self, rule_str):
        rule_list=[]
        anychar_rule = lambda c: (self.ANY_CHAR,c,1)
        exactchar_rule = lambda c:(self.EXACT_CHAR,c,1)
        rule_to_any_number = lambda rule:(rule[0],rule[1],self.ZERO_OR_MORE)
        

        for c in rule_str:
            if c == '.':                
                rule_list.append(anychar_rule(c))
            elif c == '*':
                rule = rule_list.pop()
                rule = rule_to_any_number(rule)
                rule_list.append(rule)
            else:
                rule_list.append(exactchar_rule(c))
                
                        
        return rule_list
            
        
    def test(self):
        #Some examples:
        assert not self.isMatch("aa","a")
        assert self.isMatch("aa","aa")  
        assert not self.isMatch("aaa","aa")  
        assert self.isMatch("aa", "a*")  
        assert self.isMatch("aa", ".*")  
        assert self.isMatch("ab", ".*")  
        assert self.isMatch("aab", "c*a*b")  
        assert not self.isMatch("abcd", "d*")  
        assert not self.isMatch("a", "") 
        assert self.isMatch("aaa", "a*a")  
        