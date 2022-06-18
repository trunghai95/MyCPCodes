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

	var test int
	fmt.Fscan(in, &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(tt int) {
	fmt.Fprintf(out, "Case #%d: ", tt)
	var s string
	fmt.Fscan(in, &s)

	mark := make([]bool, len(s))

	for i := len(s) - 2; i >= 0; i-- {
		if s[i] < s[i+1] {
			mark[i] = true
		} else if s[i] == s[i+1] && mark[i+1] {
			mark[i] = mark[i+1]
		}
	}

	for i := 0; i < len(s); i++ {
		fmt.Fprint(out, string(s[i]))
		if mark[i] {
			fmt.Fprint(out, string(s[i]))
		}
	}
	fmt.Fprintln(out)
}
