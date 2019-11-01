package main

import (
	"fmt"
)

func setZeroes(matrix [][]int) {
	numRow := len(matrix)
	numCol := len(matrix[0])
	firstRowShouldBeZero := false
	firstColShouldBeZero := false
	for r := 0; r < numRow; r++ {
		for c := 0; c < numCol; c++ {
			if matrix[r][c] == 0 {
				if r == 0 {
					firstRowShouldBeZero = true
				}
				if c == 0 {
					firstColShouldBeZero = true
				}
				//using first row and column to remembr if that row or column should be 0
				matrix[0][c] = 0
				matrix[r][0] = 0
			}
		}
	}
	for r := 1; r < numRow; r++ {
		for c := 1; c < numCol; c++ {
			if matrix[0][c] == 0 {
				matrix[r][c] = 0
			}
			if matrix[r][0] == 0 {
				matrix[r][c] = 0
			}
		}
	}
	if firstRowShouldBeZero {
		for c := 0; c < numCol; c++ {
			matrix[0][c] = 0
		}
	}
	if firstColShouldBeZero {
		for r := 0; r < numRow; r++ {
			matrix[r][0] = 0
		}
	}
}

func main() {
	input := [][]int{
		[]int{1, 1, 1},
		[]int{1, 0, 1},
		[]int{1, 1, 1},
	}
	fmt.Println(input)
	setZeroes(input)
	fmt.Println(input)
}
