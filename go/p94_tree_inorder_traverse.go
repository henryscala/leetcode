/* problem 94 of leetcode,
inorder traversal of binary true.
Basic idea is that:
First write the recursive solution.
Based on recursive solution, convert it to iterative solution using stack.
*/
package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	var nodeStack []*TreeNode
	var visitedStack []bool
	var result []int
	nodeStack = append(nodeStack, root)
	visitedStack = append(visitedStack, false)

	for len(nodeStack) > 0 {
		topNode := nodeStack[len(nodeStack)-1]
		topVisited := visitedStack[len(visitedStack)-1]
		if topNode == nil {
			//pop
			nodeStack = nodeStack[0 : len(nodeStack)-1]
			visitedStack = visitedStack[0 : len(visitedStack)-1]
			continue
		}

		//have visited the left branch
		if topVisited {
			//output
			result = append(result, topNode.Val)
			//pop
			nodeStack = nodeStack[0 : len(nodeStack)-1]
			visitedStack = visitedStack[0 : len(visitedStack)-1]

			//continue visit right
			nodeStack = append(nodeStack, topNode.Right)
			visitedStack = append(visitedStack, false)
			continue
		}

		//continue visit left
		visitedStack = visitedStack[0 : len(visitedStack)-1] //pop
		visitedStack = append(visitedStack, true)            //push, to mark the left branch has been visited
		nodeStack = append(nodeStack, topNode.Left)
		visitedStack = append(visitedStack, false)

	}
	return result
}

func main() {
	node1 := &TreeNode{Val: 1, Left: nil, Right: nil}
	node0 := &TreeNode{Val: 0, Left: nil, Right: nil}
	node2 := &TreeNode{Val: 2, Left: node1, Right: node0}
	result := inorderTraversal(node2)
	fmt.Println(result)
}
