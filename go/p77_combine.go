//problem 77 of leetcode
//combination
package main

import (
	"fmt"
)

func biggestValue(n, k, index int) int {
	return n - (k - index) + 1
}

func next(entry []int, n, k int) ([]int, bool) {
	for i := k - 1; i >= 0; i-- {

		if entry[i] < biggestValue(n, k, i) {

			entry[i]++
			//reset the values after i
			for j := i + 1; j < k; j++ {
				entry[j] = entry[j-1] + 1
			}
			return entry, true
		}
	}
	return nil, false
}

func combine(n int, k int) [][]int {
	var entry = make([]int, k)
	var ok bool
	for i := 0; i < k; i++ {
		entry[i] = i + 1
	}
	entry[k-1]-- //special tweaking so that later we don't need to specially handle the first entry

	var results [][]int
	var result []int

	for entry, ok = next(entry, n, k); ok; entry, ok = next(entry, n, k) {
		result = make([]int, k)
		copy(result, entry)

		results = append(results, result)

	}
	return results
}

func main() {
	k := 4
	n := 4

	fmt.Println(combine(n, k))
}
