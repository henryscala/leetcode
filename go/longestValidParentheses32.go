//problem 32 of leetcode.com
//Pair = '(' ')' | '(' Pair ')' | '()' Pair <--- these are valid
package main

import (
	"fmt"
)

func longestValidParentheses(s string) int {
	type Elem struct {
		char  byte
		index int
	}
	var stack = []Elem{}   //stack
	var weights = []byte{} //array

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			elem := Elem{char: s[i], index: i}
			stack = append(stack, elem)  //push to stack
			weights = append(weights, 0) //set the weight as 0
			continue
		}

		if len(stack) > 0 {
			topElem := stack[len(stack)-1]
			if topElem.char == '(' {
				weights[topElem.index] = 1      //change weight of the paired element
				weights = append(weights, 1)    //add the weight of the present element
				stack = stack[0 : len(stack)-1] //pop the element
			} else {
				elem := Elem{char: s[i], index: i}
				stack = append(stack, elem)
				weights = append(weights, 0) //set the weight as 0
			}
		} else {
			elem := Elem{char: s[i], index: i}
			stack = append(stack, elem)
			weights = append(weights, 0) //set the weight as 0
		}

	}

	//count the sub-sequence with max number of consecutive 1's
	maxConsecutive1Count := 0
	iStart := -1
	iEnd := -1
	weights = append(weights, 0) //add a 0 so that we don't handle the end of the array specially
	for i := 0; i < len(weights); i++ {
		if weights[i] == 1 {
			if iStart == -1 {
				iStart = i
			}
			iEnd = i
		} else {
			if iStart != -1 {
				count := iEnd + 1 - iStart
				if count > maxConsecutive1Count {
					maxConsecutive1Count = count
				}
			}
			iStart = -1
			iEnd = -1
		}
	}
	//fmt.Println("weights", weights)
	return maxConsecutive1Count
}

func assert(input string, length int) {
	res := longestValidParentheses(input)
	if res != length {
		fmt.Println("err", input, "expected", length, "actual", res)
	} else {
		fmt.Println("ok", input, "expected", length, "actual", res)
	}
}

func main() {
	assert("(()", 2)
	assert(")()())", 4)
}
