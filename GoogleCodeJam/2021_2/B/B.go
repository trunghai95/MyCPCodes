package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in   = bufio.NewReader(os.Stdin)
	out  = bufio.NewWriter(os.Stdout)
	dp1  []int
	dp2  []int
	dp3  []int
	maxn = 1000000
)

func init() {
	dp1 = make([]int, maxn+1)
	dp2 = make([]int, maxn+1)
	dp3 = make([]int, maxn+1)

	for i := 1; i <= maxn; i++ {
		dp1[i] = dp2[i-1] + 1
		for j := 1; j*j <= i; j++ {
			if i%j != 0 {
				continue
			}
			dp1[i] = max(dp1[i], dp1[i/j])
			dp1[i] = max(dp1[i], dp1[j])

			if j >= 2 {
				dp2[i] = max(dp2[i], dp1[i/j])
			}
			if i/j >= 2 {
				dp2[i] = max(dp2[i], dp1[j])
			}

			if j >= 3 {
				dp3[i] = max(dp3[i], dp1[i/j])
			}
			if i/j >= 3 {
				dp3[i] = max(dp3[i], dp1[j])
			}
		}
	}

	// fmt.Println("done")
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

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
	fmt.Fscan(in, &n)
	fmt.Fprintf(out, "Case #%d: %d\n", tt, dp3[n])
}
