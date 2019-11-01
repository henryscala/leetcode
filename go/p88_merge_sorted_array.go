package main

import (
	"fmt"
)

//nums1 is large enough to hold all values from both nums1 and nums2
func merge(nums1 []int, m int, nums2 []int, n int) {
	move(nums1, m, n)

	toIndex := 0
	fromIndex1 := n
	fromIndex2 := 0

	for (fromIndex2 < n) && (fromIndex1-n < m) {
		if nums1[fromIndex1] < nums2[fromIndex2] {
			nums1[toIndex] = nums1[fromIndex1]
			fromIndex1++
			toIndex++
		} else {
			nums1[toIndex] = nums2[fromIndex2]
			toIndex++
			fromIndex2++
		}
	}
	for fromIndex2 < n {
		nums1[toIndex] = nums2[fromIndex2]
		toIndex++
		fromIndex2++
	}
	for fromIndex1-n < m {
		nums1[toIndex] = nums1[fromIndex1]
		fromIndex1++
		toIndex++
	}
}

//move m number of elements in nums to the location started from index
//move from last to first to avoid overlap overwriting
func move(nums []int, m int, index int) {
	for i := 0; i < m; i++ {
		nums[index+m-i-1] = nums[m-i-1]
	}
}

func main() {
	var a = []int{1, 2, 3, 0, 0, 0}
	var b = []int{2, 5, 6}
	merge(a, 3, b, 3)
	fmt.Println(a)

	a = []int{1, 2, 4, 5, 6, 0}
	b = []int{3}
	merge(a, 5, b, 1)
	fmt.Println(a)
}
