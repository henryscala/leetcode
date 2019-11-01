# problem30 of leetcode
class Solution:
    #variables defined here are called class variables,
    #that are shared by all instances 
    #word_index_dict_dict = {}
    #word_count_dict = {}
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words) <= 0:
##            print("return 1")
            return []
        if len(s) < len(words[0])*len(words):
##            print("s",s)
##            print("lens(s)",len(s))
##            print("len(words[0])",len(words[0]))
##            print("len(words)",len(words))
##            print("return 2")
            return []
        word_index_dict = self.calc_word_1_indices(s,words)

        self.word_count_dict = {}
        for word in words:
            if word in self.word_count_dict:
                self.word_count_dict[word] += 1
            else:
                self.word_count_dict[word] = 1 
                
##        print("calc_word_1_indices",1, word_index_dict)
##        print("self.word_count_dict",1, self.word_count_dict)

##        print("word_index_dict",word_index_dict)
        if len(word_index_dict) <= 0 : return []
        self.word_index_dict_dict={}
        self.word_index_dict_dict[1] = word_index_dict
##        for i in range(2,len(words)+1):
##            word_index_dict=self.calc_word_indices(len(words[0]),i)
##            if len(word_index_dict) <= 0 : return []
##            self.word_index_dict_dict[i]=word_index_dict
        if len(words)>1:
            word_index_dict=self.calc_word_indices(len(words[0]),len(words))
            if len(word_index_dict) <= 0 : return []
            self.word_index_dict_dict[len(words)]=word_index_dict
        result = []
        for k,v in  self.word_index_dict_dict[len(words)].items():
            result.extend(v)
        return result 
        
    def is_legal(self,whole_str,word_len):
        words_in_str = [] 
        i = 0
        while i<len(whole_str):
            word = whole_str[i:i+word_len]
            words_in_str.append(word)
            i+=word_len
        
            
        for word in words_in_str:    
            if words_in_str.count(word) > self.word_count_dict[word]:
                return False
        return True
    
    def calc_word_indices(self,word_len,n):
        str1Words = n // 2
        str2Words = n - str1Words
        word_index_dict1 = None
        word_index_dict2 = None 
        if str1Words in self.word_index_dict_dict:
            word_index_dict1 = self.word_index_dict_dict[str1Words]
        else:
            word_index_dict1=self.calc_word_indices(word_len,str1Words)
            if len(word_index_dict1) <= 0 : return {}
            self.word_index_dict_dict[str1Words]=word_index_dict1
            
        if str2Words in self.word_index_dict_dict:
            word_index_dict2 = self.word_index_dict_dict[str2Words]
        else:
            word_index_dict2=self.calc_word_indices(word_len,str2Words)
            if len(word_index_dict2) <= 0 : return {}
            self.word_index_dict_dict[str2Words]=word_index_dict2
            
        word_index_dict = {} 
        for k1,v1 in word_index_dict1.items():
            for k2,v2 in word_index_dict2.items():
                word1 = k1+k2
                word2 = k2+k1
                legal1 = self.is_legal(word1,word_len)
                legal2 = self.is_legal(word2,word_len)
                if (not legal1) and (not legal2) : continue  
                k1k2indices = []
                k2k1indices = []
                if legal1:
                    for i1 in v1:
                        for i2 in v2:
                            if legal1 and (i1+str1Words*word_len == i2):
                                k1k2indices.append(i1)
                        
                if legal2:
                    for i1 in v1:
                        for i2 in v2:
                            if legal2 and (i2+str2Words*word_len == i1):
                                k2k1indices.append(i2)
                            
                if len(k1k2indices)>0:
                    word_index_dict[word1]=k1k2indices
                if len(k2k1indices)>0:
                    word_index_dict[word2]=k2k1indices
##        print("calc_word_indices",n, word_index_dict)
        return word_index_dict
    

    def calc_word_1_indices(self, s, words):
        word_len = len(words[0])
        words_set = set(words)
        word_index_dict = {}
        for i in range(len(s)-word_len+1):
            word=s[i:i+word_len]
            if word in words_set:
                if word in word_index_dict:
                    word_index_dict[word].append(i)
                else:
                    word_index_dict[word]=[i]
        return word_index_dict            
                
            


s = "barfoothefoobarman" 
words = ["foo","bar"]
solution = Solution()
print(solution.findSubstring(s,words))
#expected 9 0 

s="wordgoodgoodgoodbestword"
words = ["word","good","best","word"]
solution = Solution()
print(solution.findSubstring(s,words))
#expected [] 

s="barfoofoobarthefoobarman"
words=["bar","foo","the"]
solution = Solution()
print(solution.findSubstring(s,words))
#expected 6 9 12

s="a"
words=["a"]
solution = Solution()
print(solution.findSubstring(s,words))
#expected 0 
