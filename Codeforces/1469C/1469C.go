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

func solve() string {
	var n, k int
	fmt.Fscan(in, &n, &k)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &h[i])
	}

	mx := make([]int, n)
	mn := make([]int, n)

	mn[0] = h[0]
	mx[0] = h[0]
	// fmt.Fprintln(out, 0, mn[0], mx[0])
	for i := 1; i < n; i++ {
		mn[i] = max(h[i], mn[i-1]+1-k)
		mx[i] = min(h[i]+k-1, mx[i-1]+k-1)
		// fmt.Fprintln(out, i, mn[i], mx[i])
		if mn[i] > mx[i] {
			return "NO"
		}
	}
	if mn[n-1] > h[n-1] {
		return "NO"
	}
	return "YES"
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
