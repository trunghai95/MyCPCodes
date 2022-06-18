package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var n int
	var s string

	fmt.Fscan(in, &n, &s)

	var resL, resR, tmpR, tmpL int
	for i := 0; i < n; i++ {
		if s[i] == 'F' {
			tmpR = min(resR, resL+1)
			tmpL = min(resL, resR+1)
		} else if s[i] == 'O' {
			tmpR = min(resR, resL+1)
			tmpL = min(resL + 2, resR+ 1)
		} else {
			tmpL = min(resL, resR+1)
			tmpR = min(resR+2, resL+1)
		}
		resR = tmpR
		resL = tmpL
	}
	fmt.Fprintf(out, "Case #%d: %d\n", tt, min(resR, resL))
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}