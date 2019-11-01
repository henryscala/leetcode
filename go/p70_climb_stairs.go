package main

import "fmt"

func climbStairs(n int) int {
	var numSteps = make([]int, n+1)
	for i := 0; i <= n; i++ {
		numSteps[i] = -1
	}
	return climbStairsMemo(n, numSteps)
}

func climbStairsMemo(n int, numSteps []int) int {
	if numSteps[n] >= 0 {
		return numSteps[n]
	}

	var nums int
	if n == 0 {
		nums = 1

	} else if n == 1 {
		nums = 1

	} else {
		n1 := climbStairsMemo(n-1, numSteps)
		n2 := climbStairsMemo(n-2, numSteps)
		nums = n1 + n2
	}
	numSteps[n] = nums
	return nums
}

func main() {
	for n := 1; n <= 5; n++ {
		res := climbStairs(n)
		fmt.Println(n, "stairs", res, "steps")
	}
}
