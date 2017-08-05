//problem 46 of leetcode.com
//permutations of distinct values in a slice
package main

import (
	"fmt"
	"sort"
)

func permute(nums []int) [][]int {
	results := permuteNum(len(nums))

	for i := 0; i < len(results); i++ {
		for k := 0; k < len(results[i]); k++ {
			results[i][k] = nums[results[i][k]]
		}
	}
	return results
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

func permuteNum(num int) [][]int {
	nums := make([]int, num)
	for i := 0; i < num; i++ {
		nums[i] = i
	}
	var results [][]int

	var result = []int{}
	result = append(result, nums...)
	results = append(results, result)
	for true {
		foundIndex, found := findNextIndex(nums)
		if found {
			smallestIndex := findIndexWithSmalestValueIsGreaterThan(nums, foundIndex+1, nums[foundIndex])
			nums[foundIndex], nums[smallestIndex] = nums[smallestIndex], nums[foundIndex]
			sort.Ints(nums[foundIndex+1:])

			result = []int{}
			result = append(result, nums...)
			results = append(results, result)
		} else {

			break

		}

	}
	return results
}

func main() {
	nums := []int{1, 2, 3, 4}
	results := permute(nums)
	fmt.Println(results)
	fmt.Println("number", len(results))
}
