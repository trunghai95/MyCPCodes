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
		solve()
	}
}

func solve() {
	var n, m, l, r int
	var s string
	fmt.Fscan(in, &n, &m, &s)

	sum := make([]int, n+2)
	minPre := make([]int, n+2)
	maxPre := make([]int, n+2)
	for i := 1; i <= n; i++ {
		if s[i-1] == '+' {
			sum[i] = sum[i-1] + 1
		} else {
			sum[i] = sum[i-1] - 1
		}
		maxPre[i] = max(maxPre[i-1], sum[i])
		minPre[i] = min(minPre[i-1], sum[i])
	}
	minSuf := make([]int, n+2)
	maxSuf := make([]int, n+2)
	for i := n; i >= 1; i-- {
		if s[i-1] == '+' {
			minSuf[i] = min(1, minSuf[i+1]+1)
			maxSuf[i] = max(1, maxSuf[i+1]+1)
		} else {
			minSuf[i] = min(-1, minSuf[i+1]-1)
			maxSuf[i] = max(-1, maxSuf[i+1]-1)
		}
	}

	// fmt.Fprintln(out, sum)
	// fmt.Fprintln(out, minPre)
	// fmt.Fprintln(out, maxPre)
	// fmt.Fprintln(out, minSuf)
	// fmt.Fprintln(out, maxSuf)

	for i := 0; i < m; i++ {
		fmt.Fscan(in, &l, &r)
		l--
		r++

		mn := minPre[l]
		mx := maxPre[l]
		if r <= n {
			mn = min(mn, sum[l]+minSuf[r])
			mx = max(mx, sum[l]+maxSuf[r])
		}
		fmt.Fprintln(out, mx-mn+1)
	}
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
