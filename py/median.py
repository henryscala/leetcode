# -*- coding: utf-8 -*-
# problem 4 of leet code
# find median of two sorted arrays    
# the solution is from http://blog.csdn.net/yutianzuijin/article/details/11499917

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        count1=len(nums1) 
        count2=len(nums2)
        count = count1 + count2
        if count % 2 != 0:
            return self.findNth(nums1,0,count1,nums2,0,count2,count // 2 + 1)
        else: 
            return (self.findNth(nums1,0,count1,nums2,0,count2,count // 2 ) + 
                    self.findNth(nums1,0,count1,nums2,0,count2,count // 2 + 1) ) / 2.0  
    def findNth(self,nums1,f1,count1,nums2,f2,count2,n):   
        if count1 > count2:
            return self.findNth(nums2,f2,count2,nums1,f1,count1,n)
            
        if count1 == 0:
            return nums2[f2+n-1]
            
        if n == 1:
            return min(nums1[f1],nums2[f2])
            
        halfNum1 = min(n // 2, count1)
        assert halfNum1 <= count1
        halfNum2 = n - halfNum1 
        assert halfNum2 <= count2 
        
        if nums1[f1+halfNum1-1] < nums2[f2+halfNum2-1]: 
            return self.findNth(nums1,f1+halfNum1,count1-halfNum1,nums2,f2,count2,n-halfNum1)
        elif nums1[f1+halfNum1-1] > nums2[f2+halfNum2-1]: 
            return self.findNth(nums1,f1,count1,nums2,f2+halfNum2,count2-halfNum2,n-halfNum2)
        else:
            return nums1[f1+halfNum1-1]

    def test(self):
        a1=[1,2,3,4]
        a2=[5,6,7,8,9]
        assert 5 == self.findMedianSortedArrays(a1,a2)
        a1=[1,2,3,4]
        a2=[5,6,7,8]
        assert 4.5 == self.findMedianSortedArrays(a1,a2) 
        
        a1=[1,2]
        a2=[1,2]
        assert 1 == self.findNth(a1,0,2,a2,0,2,2)
        result = self.findNth(a1,0,2,a2,0,2,3) 
        print('result=',result)
        assert 2 == result 
        self.findNth(a1,0,2,a2,0,2,3)
        assert 1.5 == self.findMedianSortedArrays(a1,a2)  
        
if __name__ == '__main__':
    s = Solution()
    s.test()
        
                