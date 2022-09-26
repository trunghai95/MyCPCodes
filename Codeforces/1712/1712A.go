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

	if k == n {
		return 0
	}

	i := 0
	j := k
	res := 0
	for {
		for i < k && a[i] <= k {
			i++
		}
		for j < n && a[j] > k {
			j++
		}
		if i < k && j < n {
			res++
			i++
			j++
		} else {
			break
		}
	}
	return res
}
