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
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	i := n - 2
	for i >= 0 {
		a[i] = i + 2
		a[i+1] = i + 1
		i -= 2
	}
	if a[0] == 0 {
		a[0] = 1
	}
	for _, x := range a {
		fmt.Fprintf(out, "%d ", x)
	}
	fmt.Fprintln(out)
}
