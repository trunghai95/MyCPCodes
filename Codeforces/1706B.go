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
		solve()
	}
}

func solve() {
	var n, x int
	fmt.Fscan(in, &n)
	last := make([]int, n)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		last[i] = -1
	}

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x)
		x--
		// fmt.Println(x, last[x], mark[x], res[x])
		if last[x] == -1 || (i-last[x])%2 != 0 {
			res[x]++
			last[x] = i
		}
		// fmt.Println(mark[x], res[x])
	}

	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", res[i])
	}
	fmt.Fprintln(out)
}
