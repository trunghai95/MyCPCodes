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
	for test > 0 {
		test--
		solve()
	}
}

func solve() {
	var n, m, x int
	fmt.Fscan(in, &n, &m)
	l := n + m - 2
	cntTotal := make([]int, l/2+1)
	cnt1 := make([]int, l/2+1)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &x)
			dist := i + j
			if dist == l-dist {
				continue
			}
			if dist > l-dist {
				dist = l - dist
			}
			cntTotal[dist]++
			if x == 1 {
				cnt1[dist]++
			}
		}
	}
	res := 0
	for i := 0; i <= l/2; i++ {
		cnt0 := cntTotal[i] - cnt1[i]
		if cnt0 < cnt1[i] {
			res += cnt0
		} else {
			res += cnt1[i]
		}
	}
	fmt.Fprintln(out, res)
}
