/*
problem 44 of leetcode
wildcard matching

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/
package main

import (
	"fmt"
)

const (
	exact int = iota
	any
	wildcard
)

type PatternDescription struct {
	charType int
	char     byte
}

type MatchState struct {
	patternDescriptionIndex int
}

func match(char byte, state MatchState, pdList []PatternDescription) []MatchState {
	var result []MatchState
	pd := pdList[state.patternDescriptionIndex]
	switch pd.charType {
	case exact:
		if char == pd.char {
			newState := MatchState{}
			newState.patternDescriptionIndex = state.patternDescriptionIndex + 1
			result = append(result, newState)

			//if next state is wildcard, add another state next to it
			if newState.patternDescriptionIndex < len(pdList)-1 && pdList[newState.patternDescriptionIndex].charType == wildcard {
				newState2 := MatchState{}
				newState2.patternDescriptionIndex = newState.patternDescriptionIndex + 1
				result = append(result, newState2)
			}
		}
	case any:
		newState := MatchState{}

		newState.patternDescriptionIndex = state.patternDescriptionIndex + 1
		result = append(result, newState)

		//if next state is wildcard, add another state next to it
		if newState.patternDescriptionIndex < len(pdList)-1 && pdList[newState.patternDescriptionIndex].charType == wildcard {
			newState2 := MatchState{}
			newState2.patternDescriptionIndex = newState.patternDescriptionIndex + 1
			result = append(result, newState2)
		}

	case wildcard:
		result = append(result, state) //curr state
		newState := MatchState{}
		newState.patternDescriptionIndex = state.patternDescriptionIndex + 1
		result = append(result, newState) //new state
	}
	return result
}

func compilePattern(p string) []PatternDescription {
	var result []PatternDescription
	var lastCharType int = -1
	for i := 0; i < len(p); i++ {
		c := p[i]
		d := PatternDescription{}

		if c == '?' {
			//			if lastCharType == wildcard {
			//				continue
			//			}
			d.charType = any
			lastCharType = any
		} else if c == '*' {
			if lastCharType == wildcard {
				continue //combine multiple consequtive wildcard to one
			}
			//			if lastCharType == any {
			//				result[len(result)-1].charType = wildcard
			//				lastCharType = wildcard
			//				continue
			//			}
			d.charType = wildcard
			lastCharType = wildcard
		} else {
			d.charType = exact
			lastCharType = exact
			d.char = c
		}
		result = append(result, d)
	}
	return result
}

func isMatch(s string, p string) bool {
	//add same prefix for easy handling, otherwise, it is difficult to set the initial state(the initial state may contain more than one state in that case)
	s = "a" + s
	p = "a" + p

	pdList := compilePattern(p)
	fmt.Println("pdList", pdList)

	state := MatchState{0}
	var stateList = []MatchState{state}

	for i := 0; i < len(s); i++ {
		var newStateList []MatchState
		for _, astate := range stateList {
			if astate.patternDescriptionIndex >= len(pdList) {
				continue
			}
			list := match(s[i], astate, pdList)
			if len(list) == 0 {
				continue
			}
			newStateList = append(newStateList, list...)
		}
		if len(newStateList) == 0 {
			return false
		}
		stateList = newStateList
		fmt.Println("stateList", stateList)
	}

	for _, astate := range stateList {
		//any pattern come to the end? It means a match, otherwise, it is not.
		if astate.patternDescriptionIndex == len(pdList) {
			return true
		}
		//if the remaining is the last pattern and it is a wild card, it is also a match
		if astate.patternDescriptionIndex == len(pdList)-1 && pdList[astate.patternDescriptionIndex].charType == wildcard {
			return true
		}
	}
	return false
}

func assert(s, p string, matched bool) {
	if isMatch(s, p) != matched {
		fmt.Println(s, p, !matched)
	}

}

func main() {
	//	assert("aa", "a", false)
	//	assert("aa", "aa", true)
	//	assert("aaa", "aa", false)
	//	assert("aa", "*", true)
	//	assert("aa", "a*", true)
	//	assert("ab", "?*", true)
	//	assert("aab", "c*a*b", false)
	//	assert("", "", true)
	//	assert("", "*", true)
	//	assert("", "**", true)
	//	assert("a", "a*", true)
	//	assert("c", "*?*", true)
	//	assert("c", "?*?", false)
	assert("abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb",
		"***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**", true)
}
