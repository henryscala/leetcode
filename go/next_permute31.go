//problem 31 of leetcode.com
//next permutation
package main

import (
	"fmt"
	"sort"
)

func nextPermutation(nums []int) {
	foundIndex, found := findNextIndex(nums)
	if found {
		smallestIndex := findIndexWithSmalestValueIsGreaterThan(nums, foundIndex+1, nums[foundIndex])
		nums[foundIndex], nums[smallestIndex] = nums[smallestIndex], nums[foundIndex]
		sort.Ints(nums[foundIndex+1:])
	} else {
		sort.Ints(nums)
	}
}

//from right to left, find next index, where the value in this place is smaller than the one after it
func findNextIndex(nums []int) (int, bool) {

	for i := len(nums) - 1; i >= 1; i-- {
		prevIndex := i - 1
		if nums[prevIndex] < nums[i] {
			return prevIndex, true
		}
	}
	return -1, false
}

func findIndexWithSmalestValueIsGreaterThan(nums []int, fromIndex int, val int) int {
	smallestIndex := fromIndex
	for i := fromIndex; i < len(nums); i++ {
		if nums[i] > val && nums[i] < nums[smallestIndex] {
			smallestIndex = i
		}
	}
	return smallestIndex
}

func main() {
	nums := []int{1, 2, 3}
	nextPermutation(nums)
	fmt.Println(nums)
	nums = []int{3, 2, 1}
	nextPermutation(nums)
	fmt.Println(nums)
	nums = []int{1, 1, 5}
	nextPermutation(nums)
	fmt.Println(nums)
}
