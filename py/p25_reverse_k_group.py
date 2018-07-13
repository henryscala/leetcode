# problem 25 of leetcode
# Reverse Nodes in k-Group
# Given this linked list: 1->2->3->4->5

# For k = 2, you should return: 2->1->4->3->5

# For k = 3, you should return: 3->2->1->4->5
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        length = self.node_list_len(head)
        if length < k:
            return head 
        node = head
        newHead = None
        newTail = None 
        while k <= length: 
            nodeGroupHead = None
            nodeGroupTail = None
            
            for i in range(k):
                nodeNext = node.next
                node.next = nodeGroupHead
                nodeGroupHead = node
                if nodeGroupTail == None:
                    nodeGroupTail = node
                node = nodeNext
            length -= k
            if newHead == None:
                newHead = nodeGroupHead
                
            if newTail == None:
                newTail = nodeGroupTail
            else:
                newTail.next = nodeGroupHead
                newTail = nodeGroupTail 
        
        if newTail:
            newTail.next = node 
        return newHead
    
    def node_list_len(self,head):
        length = 0
        while head != None:
            length += 1 
            head = head.next
        return length 
    def array_to_node_list(self,arr):
        arr.reverse()
        head=None
        for v in arr:
            node=ListNode(v)
            node.next = head
            head = node 
        return head
    def node_list_to_array(self,head):
        res = [] 
        while head != None:
            res.append(head.val)
            head = head.next
        return res 

solution =  Solution()
print("test 1") 
head = solution.array_to_node_list([1,2,3,4,5])
print(solution.node_list_to_array(head))
head = solution.reverseKGroup(head, 2)
print(solution.node_list_to_array(head))
print( "test 2" ) 
head = solution.array_to_node_list([1,2,3,4,5])
print(solution.node_list_to_array(head))
head = solution.reverseKGroup(head, 3)
print(solution.node_list_to_array(head))
