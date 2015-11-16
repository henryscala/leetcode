# Given 1->2->3->4, you should return the list as 2->1->4->3.
# Definition for singly-linked list.
#Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def repr_link_list(head):
    s = ""
    while head:
        s += str(head.val) + ","
        head = head.next
    return s


def to_link_list(a):
    head = ListNode(None)
    curr = head;
    for e in a:
        curr.next = ListNode(e)
        curr = curr.next
    return head.next     

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #add head node 
        myhead_node = ListNode(None)
        myhead_node.next=head

        prev_node = myhead_node
        curr_node = head
        next_node = None 
        if curr_node:
            next_node = curr_node.next

        i = 0 
        while curr_node and next_node:
            if i % 2 == 0:
                curr_node.next = next_node.next
                next_node.next = curr_node 
                prev_node.next = next_node

                prev_node=next_node
                next_node=curr_node.next
            else:
                prev_node=curr_node
                curr_node=next_node
                next_node=next_node.next
            
            i += 1
        return myhead_node.next 

    def test(self):
        alist = to_link_list([1,2,3,4])
        print(repr_link_list(alist))
        alist = self.swapPairs(alist)
        print(repr_link_list(alist))
