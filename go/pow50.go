//problem 50 of leetcode.com

package main

import (
	"fmt"
)

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1.0
	}

	var power = n
	if n < 0 {
		power = -n
	}

	result := pow(x, power)
	if n < 0 {
		result = 1 / result
	}
	return result
}

func pow(x float64, n int) float64 {
	if n == 1 {
		return x
	}

	remain := n % 2
	half := n / 2

	p1 := pow(x, half)
	result := p1 * p1
	if remain == 1 {
		result *= x
	}

	return result
}

func main() {
	fmt.Println(myPow(2.0, 3))
	fmt.Println(myPow(2.0, -3))
}
