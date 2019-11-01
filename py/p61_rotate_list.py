#problem 61 of leetcode 
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return head
        
        tail = head
        count = 1 
        while tail.next is not None:
            tail = tail.next
            count += 1 

        tail.next = head #make the list a cycle list
        k=k%count
        for i in range(count-k):
            head = head.next
            tail = tail.next
        tail.next = None
        return head

if __name__ == '__main__':
    s = Solution()
    
    
        
