package main

import (
	"fmt"
	"strings"
)

// A TreeNode is a struct
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (node *TreeNode) String() string {
	if node == nil {
		return "nil"
	}
	var sb strings.Builder
	sb.WriteString(fmt.Sprint(node.Val))
	sb.WriteString("[")
	left := node.Left.String()
	right := node.Right.String()
	sb.WriteString(left)
	sb.WriteString(",")
	sb.WriteString(right)
	sb.WriteString("]")
	return sb.String()
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	var levelsNode [][]*TreeNode
	var levelNode = []*TreeNode{root}
	var levelNodeNew []*TreeNode
	levelsNode = append(levelsNode, levelNode)

	for len(levelNode) > 0 {
		for _, node := range levelNode {
			if node.Left != nil {
				levelNodeNew = append(levelNodeNew, node.Left)
			}
			if node.Right != nil {
				levelNodeNew = append(levelNodeNew, node.Right)
			}

		}
		if len(levelNodeNew) > 0 {
			levelsNode = append(levelsNode, levelNodeNew)

		}
		levelNode = levelNodeNew
		levelNodeNew = nil
	}
	var levelsInt [][]int
	var levelInt []int
	for _, levelNode = range levelsNode {
		levelInt = nil
		for _, node := range levelNode {
			levelInt = append(levelInt, node.Val)
		}
		levelsInt = append(levelsInt, levelInt)
	}
	return levelsInt
}

func main() {

	var left = &TreeNode{9, nil, nil}
	var rightleft = &TreeNode{15, nil, nil}
	var rightright = &TreeNode{7, nil, nil}
	var right = &TreeNode{20, rightleft, rightright}
	var root = &TreeNode{3, left, right}

	fmt.Println(root)
	var levels = levelOrder(root)
	fmt.Println(levels)
}
