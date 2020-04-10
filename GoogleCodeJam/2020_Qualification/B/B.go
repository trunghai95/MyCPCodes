package main

import "fmt"

func main() {
	var test int

	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(t int) {
	fmt.Printf("Case #%v: ", t)
	var s string
	var cur int
	fmt.Scanf("%s\n", &s)
	for _, c := range s {
		d := int(c - '0')
		for cur < d {
			fmt.Print("(")
			cur++
		}
		for cur > d {
			fmt.Print(")")
			cur--
		}
		fmt.Print(d)
	}
	for cur > 0 {
		fmt.Print(")")
		cur--
	}
	fmt.Println()
}
