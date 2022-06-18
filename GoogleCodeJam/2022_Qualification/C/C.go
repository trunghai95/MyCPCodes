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
	for i := 1; i <= test; i++ {
		fmt.Fprintf(out, "Case #%d: %d\n", i, solve())
	}
}

func solve() int {
	var n int
	fmt.Fscan(in, &n)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s[i])
	}
	sort.Ints(s)
	res := 0
	for i := 0; i < n; i++ {
		if s[i] > res {
			res++
		}
	}
	return res
}
