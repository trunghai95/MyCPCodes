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

const INF = 10000000

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var x, y int
	var s string

	fmt.Fscan(in, &x, &y, &s)
	n := len(s)
	dp := make([][2]int, n)
	if s[0] == 'C' {
		dp[0][0] = 0
		dp[0][1] = INF
	} else if s[0] == 'J' {
		dp[0][0] = INF
		dp[0][1] = 0
	} else {
		dp[0][0], dp[0][1] = 0, 0
	}

	// fmt.Fprintln(out, s)

	for i := 1; i < n; i++ {
		if s[i] == 'C' {
			dp[i][1] = INF
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]+y)
		} else if s[i] == 'J' {
			dp[i][0] = INF
			dp[i][1] = min(dp[i-1][1], dp[i-1][0]+x)
		} else {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]+y)
			dp[i][1] = min(dp[i-1][1], dp[i-1][0]+x)
		}
	}

	// fmt.Fprintln(out, dp)

	fmt.Fprintf(out, "Case #%d: %d\n", tt, min(dp[n-1][0], dp[n-1][1]))
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
