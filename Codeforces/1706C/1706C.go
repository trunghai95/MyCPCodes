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
	for i := 0; i < test; i++ {
		fmt.Fprintln(out, solve())
	}
}

func solve() int64 {
	var n int
	fmt.Fscan(in, &n)
	h := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &h[i])
	}

	if n%2 != 0 {
		var res int64
		for i := 1; i < n; i += 2 {
			tmp := max(h[i-1], h[i+1]) + 1
			res += max(tmp-h[i], 0)
		}
		return res
	}

	dp := make([][]int64, 2)
	dp[0] = make([]int64, n)
	dp[1] = make([]int64, n)
	for i := 1; i < n-1; i++ {
		tmp := max(h[i-1], h[i+1]) + 1
		tmp = max(tmp-h[i], 0)

		// fmt.Println(i, tmp)

		if i >= 2 {
			dp[0][i] = dp[0][i-2] + tmp
			dp[1][i] = dp[1][i-2] + tmp

			if i >= 3 {
				dp[1][i] = min(dp[1][i], dp[0][i-3]+tmp)
			}
		} else {
			dp[0][i] = tmp
			dp[1][i] = tmp
		}
	}

	// fmt.Println(dp)
	return min(dp[0][n-3], min(dp[0][n-2], dp[1][n-2]))
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}
