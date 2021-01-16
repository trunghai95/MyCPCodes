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
	fmt.Fscan(in, &t)
	for t > 0 {
		t--
		fmt.Fprintln(out, solve())
	}
}

func solve() int {
	var n, m int
	fmt.Fscan(in, &n)
	r := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &r[i+1])
		if i > 0 {
			r[i+1] += r[i]
		}
	}
	n++
	fmt.Fscan(in, &m)
	b := make([]int, m+1)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &b[i+1])
		if i > 0 {
			b[i+1] += b[i]
		}
	}
	m++
	res := 0
	for _, rr := range r {
		for _, bb := range b {
			sum := rr + bb
			if sum > res {
				res = sum
			}
		}
	}
	return res
}
