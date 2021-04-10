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
	var n int
	var k int64
	fmt.Fscan(in, &n, &k)
	x := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i])
	}

	g := abs(x[0])
	for i := 1; i < n; i++ {
		g = gcd(g, abs(x[i]))
	}

	if k%g == 0 {
		fmt.Fprintln(out, "YES", g)
	} else {
		fmt.Fprintln(out, "NO", g)
	}
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	if b == 0 {
		return a
	}
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
