package main

/*problem 58 of leetcode) */

import (
	"fmt"
)

func lengthOfLastWord(s string) int {
	const (
		inBlank int = iota
		inWord
	)
	s = " " + s + " " //so that we don't need to specially handle start/end of the string
	state := inBlank

	var wordStart, wordEnd int
	for i := 1; i < len(s); i++ {
		switch s[i] {
		case ' ':
			switch state {
			case inBlank:
			//do nothing
			case inWord:
				wordEnd = i
				state = inBlank
			}
		default:
			switch state {

			case inBlank:
				wordStart = i
				state = inWord
			case inWord:
				//do nothing
			}
		}

	}

	return wordEnd - wordStart
}

func main() {
	fmt.Println(lengthOfLastWord("hello world"))
	fmt.Println(lengthOfLastWord(""))
	fmt.Println(lengthOfLastWord(" "))
	fmt.Println(lengthOfLastWord("a "))
}
