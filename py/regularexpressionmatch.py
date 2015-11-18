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
        
        i_input = 0 
        rule_index_list = [0]
        #print("isMatch",input_str, rule_str)
        while i_input<count_input:
            char = input_str[i_input]
            rule_index_list=self.transitStates(rule_list, rule_index_list, char)
            #print (i_input,"--",char,"---",rule_index_list)
            if not rule_index_list:
                return False
            i_input += 1             
        #exhausted the input str
        if i_input == count_input:
                
            to_the_end = any(map ( (lambda e:e >=0 and e >= count_rule),  rule_index_list))
            if to_the_end :
                return True
            else : 
                max_index = max(rule_index_list) 
                
                all_wildcard_match = all(map ( lambda i:rule_list[i][2]==self.ZERO_OR_MORE, range(max_index,count_rule)) )
                if all_wildcard_match:
                    return True
                else:    
                    return False 
        else:
            
            return False 
            
            
    
                
            
    #transit a state, the state is represented by the rule_index  
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
        
    #transit multiple state    
    def transitStates(self, rule_list, list_rule_index, char):
        list_new_rule_index = []
        for rule_index in list_rule_index :
            new_rule_index = -1
            curr_rule_index = rule_index
            while True:
                new_rule_index, ok = self.transitState(rule_list,curr_rule_index,char) 
                if ok:
                    list_new_rule_index.append(new_rule_index)
                    curr_rule = rule_list[curr_rule_index]
                    if curr_rule[2] == self.ZERO_OR_MORE: # match on 0 or more,  need to attempt further 
                        curr_rule_index += 1 
                    else:
                        break 
                        
                else:
                    break 
                    
        return list_new_rule_index
                
                    
    #some rules are left recursive, for example "a*a", change it to right recursive aa* 
    #some rules are redundant, for example "a*.*", change it to ".*" 
    #need to remove the duplicate rules                 
    def addRule(self,rule_list,rule):
        count = len(rule_list)
        if rule_list:#non empty
            last_rule = rule_list[count-1]
            char_type,match_char,cardinal = last_rule
            char_type_1,match_char_1,cardinal_1 = rule
            
            if cardinal == self.ZERO_OR_MORE:
                if last_rule == rule:
                    return 
                    
        rule_list.append(rule)
        
        
    def parseRule(self, rule_str):
        rule_list=[]
        anychar_rule = lambda c: (self.ANY_CHAR,c,1)
        exactchar_rule = lambda c:(self.EXACT_CHAR,c,1)
        rule_to_any_number = lambda rule:(rule[0],rule[1],self.ZERO_OR_MORE)
        

        for c in rule_str:
            if c == '.':   
                self.addRule(rule_list,anychar_rule(c))
                
            elif c == '*':
                rule = rule_list.pop()
                rule = rule_to_any_number(rule)
                self.addRule(rule_list,rule)
            else:
                self.addRule(rule_list,exactchar_rule(c))
                
        #print("rule_list",rule_list)                
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
        assert not self.isMatch("aaa", "aaaa") 
        assert self.isMatch( "baabbbaccbccacacc", "c*..b*a*a.*a..*c" ) 

if __name__=='__main__' : 
    s=Solution()
    s.test()       
    