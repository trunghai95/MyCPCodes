package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	var t int
	fmt.Fscanln(in, &t)
	for t > 0 {
		t--
		fmt.Fprintln(out, solve())
	}
}

func solve() int {
	var s string
	fmt.Fscanln(in, &s)
	x := make([]bool, len(s))
	res := 0
	for i := range s {
		if i > 0 && !x[i-1] && s[i] == s[i-1] {
			x[i] = true
			res++
		} else if i > 1 && !x[i-2] && s[i] == s[i-2] {
			x[i] = true
			res++
		}
	}
	return res
}
