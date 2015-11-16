#Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        tail = None
        
        while l1 and l2:
            if not head:
                if l1.val <= l2.val:
                    head = l1
                    tail = l1
                    l1 = l1.next
                else:
                    head = l2
                    tail = l2
                    l2 = l2.next
            else:
                if l1.val <= l2.val:
                    tail.next = l1
                    tail = l1
                    l1 = l1.next
                else:
                    tail.next = l2
                    tail = l2
                    l2 = l2.next

        if not tail:
            if l1:
                return l1
            if l2:
                return l2
        else:    
            while l1 :
                tail.next = l1
                tail = l1
                l1 = l1.next
                        
            while l2:
                tail.next = l2
                tail = l2
                l2 = l2.next

        return head    
            
