package main

/*problem 38 of leetcode, count and say */
import (
	"bytes"
	"fmt"
	"strconv"
)

func countAndSay(n int) string {
	var buf bytes.Buffer
	strNum := "1"
	for i := 1; i < n; i++ {

		count := 1
		char := strNum[0]
		for k := 1; k < len(strNum); k++ {
			if strNum[k] != char {
				strCount := strconv.Itoa(count)

				buf.WriteString(strCount)
				buf.WriteByte(char)
				count = 1
				char = strNum[k]
			} else {
				count++
			}
		}

		strCount := strconv.Itoa(count)

		buf.WriteString(strCount)
		buf.WriteByte(char)

		strNum = buf.String()
		buf.Reset()
	}

	return strNum
}

func main() {
	fmt.Println(countAndSay(4))
}
