#problem 26 
class Solution(object):
    def remove(self,nums,count,fromIndex,remove_count):
        for i in range(fromIndex,count-remove_count):
            nums[i] = nums[i+remove_count]
        return count - remove_count    
      
    def removeDuplicates(self, nums):
        count = len(nums)
        top = 0
        ahead = top +1
        while ahead < count:
            if nums[ahead] == nums[top]:
                ahead += 1
            else: 
                top += 1
                if ahead > top:
                    nums[top] = nums[ahead]
                ahead +=  1
        if count <=0:
            return 0
        else:
            return top  + 1
    #a slow method, do not use it     
    def removeDuplicates2(self, nums):
        count = len(nums)
        iright = count - 1
        ileft = iright

                
        while iright >= 0:
            while ileft >=0:
                if nums[ileft] == nums[iright]:
                    ileft -= 1   
                else:
                    break
            
            delta = iright - ileft
            if delta > 1: #there is duplicates 
                count=self.remove(nums,count,ileft+1,delta-1)
            iright = ileft
            ileft-=1
        return count             
                        
                
        """
        :type nums: List[int]
        :rtype: int
        """
    def test(self):
        a=[1,2,3,3,4]
        result=self.remove(a,5,3,2)
        assert result == 3
        assert a[:3] == [1,2,3]
        
        a=[1,2,3,3,4]
        result = self.removeDuplicates(a)
        #print ("result=",result)
        assert result == 4 
        #print ("result_list",a[:4])
        assert a[:4] == [1,2,3,4]
        
        a=[1,1,2,2,3,3,4,4]
        
        print("origin",a)
        print("original len",len(a))
        result = self.removeDuplicates(a)
        print("new len",result)
        print("new",a[:result])
        
        a=[1,1,1,2]
        
        #print("origin",a)
        #print("original len",len(a))
        result = self.removeDuplicates(a)
        #print("new len",result)
        #print("new",a[:result])
        
        
if __name__ == '__main__': 
    s = Solution()
    s.test()
        