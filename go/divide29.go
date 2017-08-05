//problem 29 of leetcode.com
//divide two integers without using * / %
package main

import (
	"fmt"
)

func divide(dividend int, divisor int) int {
	var MaxInt int = 2147483647
	var MinInt int = -2147483648

	if divisor == 0 {
		return MaxInt
	}
	if dividend == MinInt && divisor == -1 {
		return MaxInt
	}
	var sign int = 1
	var dividend_u uint
	var divisor_u uint
	if dividend < 0 {
		sign = -1
		dividend_u = uint(-dividend)
	} else {
		dividend_u = uint(dividend)
	}
	if divisor < 0 {
		sign *= -1
		divisor_u = uint(-divisor)
	} else {
		divisor_u = uint(divisor)
	}
	if dividend_u < divisor_u {
		return 0
	}

	var times uint = 0
	var newDivisor_u = divisor_u
	for dividend_u >= newDivisor_u {
		newDivisor_u = newDivisor_u << 1
		times++
	}

	newDivisor_u = newDivisor_u >> 1
	dividend_u -= newDivisor_u

	var times2 uint = 0

	for dividend_u >= divisor_u {
		dividend_u -= divisor_u
		times2++
	}

	var quotient int
	if times > 0 {
		times--
		quotient = int((1<<times)+times2) * sign
	} else {
		quotient = int(times2) * sign
	}

	return quotient
}

func main() {
	fmt.Println(divide(1004958205, -2137325331))
	//fmt.Println(divide(-2147483648, -1))
	//fmt.Println(divide(-2147483648, 1))
	//fmt.Println(divide(100, -10))
	//fmt.Println(divide(15, 3))
	//fmt.Println(divide(0, 1))
	//fmt.Println(divide(1, 1))
}
