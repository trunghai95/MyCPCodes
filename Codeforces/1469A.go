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

func solve() string {
	var s string
	fmt.Fscanln(in, &s)
	n := len(s)
	if n%2 != 0 || s[0] == ')' || s[n-1] == '(' {
		return "NO"
	}
	return "YES"
}
