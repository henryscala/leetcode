//problem 28 of leetcode.com
//implement strstr function
package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	lenHay := len(haystack)
	lenNeedle := len(needle)

	for i := 0; i <= lenHay-lenNeedle; i++ {
		if haystack[i:i+lenNeedle] == needle {
			return i
		}
	}
	return -1
}

func main() {
	fmt.Println(strStr("hello world, yeah", "world"))
	fmt.Println(strStr("a", "a"))
	fmt.Println(strStr("", ""))
}
