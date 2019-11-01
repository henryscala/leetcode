/*
problem 53 of leetcode
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

I can only figure out a brute-force solution, the below article described
a solution with O(n). The algorithm is called Kadane algorithm.
https://medium.com/@marcellamaki/finding-the-maximum-contiguous-sum-in-an-array-and-kadanes-algorithm-e303cd4eb98c
*/

package main

import "fmt"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func maxSubArray(nums []int) int {
	var globalMaxSum = nums[0]
	var currMaxSum = nums[0]
	for i := 1; i < len(nums); i++ {
		currMaxSum = max(nums[i], nums[i]+currMaxSum)
		globalMaxSum = max(currMaxSum, globalMaxSum)
	}
	return globalMaxSum
}

func main() {
	var nums = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	var res = maxSubArray(nums)
	fmt.Println(res)
}
