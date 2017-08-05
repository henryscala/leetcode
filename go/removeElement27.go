//problem 27 of leetcode.com
//remove element, first sort. and then remove the consecutive values
//note: there are clever solutions beside my solution.
//1: use two pointers, one is slow runner, and the other is fast runner. If faster runner encounters the val, it skip it, otherwise, it update value at slow runner, and inc the slow runner. At last the slower runner pointer is the index.
//2: when a value is met, exchange it with the last one and decrease the length.
package main

import (
	"fmt"
	"sort"
)

func removeElement(nums []int, val int) int {
	length := len(nums)
	sort.Ints(nums)
	iBegin := -1
	iEnd := -1

	for i := 0; i < length; i++ {
		if nums[i] == val {
			if iBegin == -1 {
				iBegin = i
			}
			iEnd = i
		}
	}
	iEnd++
	if iBegin == -1 {
		return length
	}
	delta := iEnd - iBegin

	srcIBegin := length - delta

	//handle the overlap case
	if srcIBegin < iEnd {
		srcIBegin = iEnd
	}

	copy(nums[iBegin:iEnd], nums[srcIBegin:length])
	return length - delta
}

func main() {
	nums := []int{2, 2, 3}
	len := removeElement(nums, 2)
	fmt.Println(len)
	fmt.Println(nums)
}
