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
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	res := 0
	for i := 0; i < n-1; i++ {
		j := i
		for a[j] != i+1 {
			j++
		}
		res += j - i + 1
		for k := i; k <= j; k++ {
			l := j - (k - i)
			if l <= k {
				break
			}
			a[k], a[l] = a[l], a[k]
		}
	}

	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}
