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
	fmt.Fprintf(out, "Case #%d:\n", tt)
	var r, c int
	fmt.Fscan(in, &r, &c)

	// first row
	fmt.Fprint(out, "..+")
	for i := 1; i < c; i++ {
		fmt.Fprint(out, "-+")
	}
	for i := 0; i < r; i++ {
		if i == 0 {
			fmt.Fprint(out, "\n.")
		} else {
			fmt.Fprint(out, "\n|")
		}
		for j := 0; j < c; j++ {
			fmt.Fprint(out, ".|")
		}
		fmt.Fprint(out, "\n+")
		for j := 0; j < c; j++ {
			fmt.Fprint(out, "-+")
		}
	}
	fmt.Fprintln(out)
}
