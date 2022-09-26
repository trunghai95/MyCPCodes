package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

const (
	MAX = 1000000000
)

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 0; i < test; i++ {
		fmt.Fprintln(out, solve())
	}
}

func solve() int {
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	sort.Ints(a)
	for i := 0; i < k; i++ {
		a[i] = MAX
	}
	if n == 2 {
		return min(a[0], a[1])
	}
	sort.Ints(a)
	res := a[0] * 2

	return min(a[n-2], a[0]*2)
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
