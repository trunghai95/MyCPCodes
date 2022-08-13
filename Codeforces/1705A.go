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

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 0; i < test; i++ {
		if solve() {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}

func solve() bool {
	var n, x int
	fmt.Fscan(in, &n, &x)
	a := make([]int, n*2)
	for i := 0; i < n*2; i++ {
		fmt.Fscan(in, &a[i])
	}
	sort.Ints(a)
	for i := 0; i < n; i++ {
		if a[n+i] - a[i] < x {
			return false
		}
	}
	return true
}
