//problem 100 of leetcode
//judge if two trees are the same
//I used the way to access the two Tree in leveled way, from top level to bottom level(not pre-order,post-order or mid-order).My way does not use recursive call.
//The recursive call way is clever and with less lines of code.
package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTreeNodes(plist []*TreeNode, qlist []*TreeNode) (result bool, pNewList, qNewList []*TreeNode) {

	if len(plist) != len(qlist) {
		return false, nil, nil
	}
	for i := 0; i < len(plist); i++ {
		p := plist[i]
		q := qlist[i]
		if (p == nil && q != nil) || (q == nil && p != nil) {
			return false, nil, nil
		}
		if p == nil && q == nil {
			continue
		}
		if p.Val != q.Val {
			return false, nil, nil
		}
		pNewList = append(pNewList, p.Left)
		pNewList = append(pNewList, p.Right)
		qNewList = append(qNewList, q.Left)
		qNewList = append(qNewList, q.Right)
	}
	return true, pNewList, qNewList
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	pTreeNodes := []*TreeNode{p}
	qTreeNodes := []*TreeNode{q}
	var yes bool
	for {
		yes, pTreeNodes, qTreeNodes = isSameTreeNodes(pTreeNodes, qTreeNodes)
		if !yes {
			return false
		}
		if len(pTreeNodes) == 0 && len(qTreeNodes) == 0 {
			break
		}
	}
	return true
}

func main() {
	var p, q *TreeNode
	p = &TreeNode{Val: 0, Left: nil, Right: &TreeNode{Val: 1, Left: nil, Right: nil}}
	q = &TreeNode{Val: 0, Right: nil, Left: &TreeNode{Val: 1, Left: nil, Right: nil}}
	if isSameTree(p, q) {
		fmt.Println("error")
	}
}
