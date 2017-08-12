package main

/*problem 79 of leetcode
I didn't figure out the solution. My solution works, but exceed the time limit.
The below solution is borrowed from other guy.
My mistakes are that I try to store all intermediate solutions starting from any positions,
it cost so much memory and time when the board is big and input is long.

The below solution however, only store the intermediate solutions starting from one position.

*/

import (
	"fmt"
)

var visited [][]bool
var numRow int
var numCol int

func existAt(board [][]byte, row, col int, word string, index int) bool {
	if index == len(word) {
		return true
	}
	if row < 0 || col < 0 || row >= numRow || col >= numCol {
		return false
	}

	if board[row][col] != word[index] || visited[row][col] {
		return false
	}

	visited[row][col] = true
	yes := existAt(board, row+1, col, word, index+1) ||
		existAt(board, row-1, col, word, index+1) ||
		existAt(board, row, col+1, word, index+1) ||
		existAt(board, row, col-1, word, index+1)
	visited[row][col] = false
	return yes
}

func exist(board [][]byte, word string) bool {
	numRow = len(board)
	numCol = len(board[0])
	visited = make([][]bool, numRow)

	for row := 0; row < numRow; row++ {
		line := make([]bool, numCol)
		for col := 0; col < numCol; col++ {
			line[col] = false
		}
		visited[row] = line
	}

	for row := 0; row < numRow; row++ {
		for col := 0; col < numCol; col++ {
			if existAt(board, row, col, word, 0) {
				return true
			}
		}
	}

	return false
}

func main() {
	board := [][]byte{
		[]byte{'A', 'B', 'C', 'E'},
		[]byte{'S', 'F', 'C', 'S'},
		[]byte{'A', 'D', 'E', 'E'},
	}
	fmt.Println(exist(board, "ABCCED"))
	board = [][]byte{}
	for row := 0; row < 20; row++ {
		line := make([]byte, 20)
		for col := 0; col < 20; col++ {
			line[col] = 'a'
		}
		board = append(board, line)
	}
	word := make([]byte, 400)
	for i := 0; i < 400; i++ {
		word[i] = 'a'
	}
	fmt.Println(exist(board, string(word)))
}
