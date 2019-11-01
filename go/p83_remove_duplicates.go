package main

/*
 * Definition for singly-linked list.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	var cur, newHead, newTail *ListNode
	if head == nil {
		return nil
	}
	cur = head.Next
	val := head.Val
	newHead = head
	newTail = head

	for cur != nil {
		if cur.Val == val {
			cur = cur.Next

		} else {
			val = cur.Val
			newTail.Next = cur
			newTail = cur
			cur = cur.Next
		}
	}
	newTail.Next = nil
	return newHead
}

func main() {

}
