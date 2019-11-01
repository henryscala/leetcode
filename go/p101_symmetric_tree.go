package main

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if nil == root {
		return true
	}

	var nodeList = []*TreeNode{root}
	for isSymmetricNodeList(nodeList) {
		var newList []*TreeNode
		for _, node := range nodeList {
			if node == nil {
				continue
			}
			newList = append(newList, node.Left)
			newList = append(newList, node.Right)
		}
		if newList == nil {
			return true
		}
		nodeList = newList
	}
	return false
}

func isSymmetricNodeList(nodeList []*TreeNode) bool {
	left := 0
	right := len(nodeList) - 1
	for left < right {
		if nodeList[left] == nil && nodeList[right] != nil {
			return false
		}
		if nodeList[left] != nil && nodeList[right] == nil {
			return false
		}
		if nodeList[left] != nil && nodeList[right] != nil {
			if nodeList[left].Val != nodeList[right].Val {
				return false
			}
		}
		left++
		right--
	}
	return true
}

func main() {
	isSymmetric(nil)
}
