//problem 67 of leetcode
package main

import (
	"fmt"
)

func addBinary(a string, b string) string {
	a1 := []byte(a)
	b1 := []byte(b)
	la := len(a1)
	lb := len(b1)

	if la != lb {
		//make sure a1 is longer
		if lb > la {
			a1, b1 = b1, a1
			la, lb = lb, la
		}
		delta := la - lb
		leading0 := make([]byte, delta)
		for i := 0; i < delta; i++ {
			leading0[i] = 0x30
		}
		b1 = append(leading0, b1...)
	}
	//fmt.Println("a1", a1)
	//fmt.Println("b1", b1)

	// now b1 and a1 has same length
	//	for i := 0; i < la; i++ {
	//		a1[i] -= 0x30
	//		b1[i] -= 0x30
	//	}
	//fmt.Println("a1-2", a1)
	//fmt.Println("b1-2", b1)
	var carry byte = 0
	for i := la - 1; i >= 0; i-- {
		a1[i] = a1[i] + (b1[i] & 0x0F) + carry
		if a1[i]&0x0F >= 2 {
			carry = 1
			a1[i] -= 2
		} else {
			carry = 0
		}
		//fmt.Println("i", i, "a1", a1, "carry", carry)
	}
	var result []byte
	//fmt.Println("at last cary", carry, "a1", a1)
	if carry == 0 {
		result = a1
	} else {
		result = append(result, 0x31)
		result = append(result, a1...)
	}
	//	for i := 0; i < len(result); i++ {
	//		result[i] += 0x30
	//	}
	return string(result)
}

func main() {
	a := "11"
	b := "1"
	fmt.Println(addBinary(a, b))
}
