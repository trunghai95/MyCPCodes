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
	var test int
	fmt.Fscan(in, &test)
	for test > 0 {
		solve()
		test--
	}
	out.Flush()
}

func solve() {
	var n, x, m, l, r int
	fmt.Fscan(in, &n, &x, &m)
	lo, hi := x, x
	for m > 0 {
		m--
		fmt.Fscan(in, &l, &r)
		if r >= lo && l <= hi {
			if l < lo {
				lo = l
			}
			if r > hi {
				hi = r
			}
		}
	}
	fmt.Fprintln(out, hi-lo+1)
}
