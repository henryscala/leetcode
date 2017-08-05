//problem 69 of leetcode
//calculate sqrt
//my way to do it is the stupid and straightforward way. There are other ways:
//1 binary search, binary search way is easy to understand
//2 newton's way, newton's way is clever, but I don't know how newton find this way :-)
package main

import (
	"fmt"
)

func mySqrt(x int) int {
	if x <= 0 {
		return x
	}
	i := 1
	s := i
	for s < x {
		i++
		s = i * i
	}
	if s == x {
		return i
	}
	return i - 1

}

func main() {
	for i := 0; i <= 100; i++ {
		fmt.Println(i, "--", mySqrt(i))
	}

}
