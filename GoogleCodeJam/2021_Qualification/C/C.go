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
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var n, c int
	fmt.Fscan(in, &n, &c)
	fmt.Fprintf(out, "Case #%d: ", tt)
	if c < n-1 || c > n*(n+1)/2-1 {
		fmt.Fprintf(out, "IMPOSSIBLE\n")
		return
	}
	a := make([]int, n)
	for i := range a {
		a[i] = i + 1
	}
	c -= n - 1

	for i := n - 2; c > 0; i-- {
		j := min(n-1, i+c)
		rev(a, i, j)
		c -= j - i
	}
	for _, x := range a {
		fmt.Fprintf(out, "%d ", x)
	}
	fmt.Fprintln(out)
}

func rev(a []int, l, r int) {
	for i := l; i <= r; i++ {
		j := r - (i - l)
		if j <= i {
			return
		}
		a[i], a[j] = a[j], a[i]
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
