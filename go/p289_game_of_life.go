package main

import "fmt"

func gameOfLife(board [][]int) {
	numRow := len(board)
	numCol := len(board[0])

	type Cell struct {
		col, row int
	}

	allValidNeighbours := func(col, row int) []Cell {
		var result []Cell
		cols := []int{col - 1, col, col + 1}
		rows := []int{row - 1, row, row + 1}
		for _, c := range cols {
			if c < 0 || c >= numCol {
				continue
			}
			for _, r := range rows {
				if r < 0 || r >= numRow {
					continue
				}
				if r == row && c == col {
					continue
				}
				result = append(result, Cell{col: c, row: r})
			}
		}
		return result
	}

	countNeighbourPopulation := func(col, row int) {
		var n int
		neighbours := allValidNeighbours(col, row)
		//fmt.Println("neighbours", neighbours)
		for _, neighbour := range neighbours {
			if board[neighbour.row][neighbour.col]&0xFF == 1 {
				n++
			}
		}
		board[row][col] += (n << 8)
	}

	for r := 0; r < numRow; r++ {
		for c := 0; c < numCol; c++ {
			countNeighbourPopulation(c, r)
			//fmt.Println("row", r, "col", c, "population", board[r][c]>>8)
		}
	}

	//fmt.Println("after calc population", board)

	for r := 0; r < numRow; r++ {
		for c := 0; c < numCol; c++ {
			neighborLiveNum := board[r][c] >> 8
			if board[r][c]&0xFF == 1 { //alive
				if neighborLiveNum == 2 || neighborLiveNum == 3 {
					board[r][c] = 1 //continue alive
				} else {
					board[r][c] = 0 //goto die
				}
			} else {
				if neighborLiveNum == 3 {
					board[r][c] = 1 //goto alive
				} else {
					board[r][c] = 0 //continue die
				}
			}
		}
	}
}

func main() {
	input := [][]int{
		[]int{0, 1, 0},
		[]int{0, 0, 1},
		[]int{1, 1, 1},
		[]int{0, 0, 0},
	}
	fmt.Println(input)
	gameOfLife(input)
	fmt.Println(input)
}
