package main

//problem 66 of leetcode

import (
	"fmt"
)

func plusOne(digits []int) []int {
	var carry = 1
	for i := len(digits) - 1; i >= 0; i-- {
		digits[i] += carry
		if digits[i] >= 10 {
			carry = 1
			digits[i] -= 10
		} else {
			carry = 0
			break
		}
	}
	if carry > 0 {
		result := []int{}
		result = append(result, carry)
		result = append(result, digits...)
		return result
	}
	return digits
}

func main() {
	digits := []int{9, 9, 9}
	fmt.Println(plusOne(digits))
}
