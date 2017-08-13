/*problem 51 of leetcode
print the nqueens solution like below:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

package main

import (
	"fmt"
)

func isValid(n int, board []int, index int) bool {
	if board[index] < 0 {
		return false
	}
	for i := 0; i < index; i++ {
		if board[i] == board[index] { //same column
			return false
		}
		if board[i]-i == board[index]-index { //same diagnal 1
			return false
		}
		if board[i]+i == board[index]+index { //same diagnal 2
			return false
		}
	}
	return true
}

var boards [][]int

func solveNQueensOnBoard(n int, board []int, index int) {
	//fmt.Println(board, index)
	board[index]++
	if board[index] >= n {
		board[index] = -1
		if index != 0 {
			solveNQueensOnBoard(n, board, index-1)
		}
		return
	}

	if !isValid(n, board, index) {
		solveNQueensOnBoard(n, board, index) //attempt same index
		return
	}

	if index == n-1 {
		saveBoard := make([]int, n)
		copy(saveBoard, board)
		boards = append(boards, saveBoard)
		board[index] = -1
		if index != 0 {
			solveNQueensOnBoard(n, board, index-1)
		}
	} else {
		solveNQueensOnBoard(n, board, index+1)
	}
}

func board2string(board []int) []string {
	n := len(board)
	byteBoard := make([][]byte, n)
	for i := 0; i < n; i++ {
		line := make([]byte, n)
		for k := 0; k < n; k++ {
			line[k] = '.'
		}
		line[board[i]] = 'Q'
		byteBoard[i] = line
	}
	result := make([]string, n)
	for i := 0; i < n; i++ {
		result[i] = string(byteBoard[i])
	}
	return result
}

func solveNQueens(n int) [][]string {
	var board = make([]int, n)
	for i := 0; i < n; i++ {
		board[i] = -1
	}
	boards = [][]int{}
	solveNQueensOnBoard(n, board, 0)
	result := make([][]string, len(boards))
	for i := 0; i < len(boards); i++ {
		result[i] = board2string(boards[i])
	}
	return result
}

func main() {
	fmt.Println(solveNQueens(1))
	//fmt.Println(solveNQueens(8))
}
