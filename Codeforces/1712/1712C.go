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
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	mp := make(map[int]bool)
	res := 0
	for {
		ok := true
		for i := n - 1; i > 0; i-- {
			if mp[a[i]] {
				a[i] = 0
			}
			if mp[a[i-1]] {
				a[i-1] = 0
			}
			// fmt.Println(a, mp)
			if a[i-1] > a[i] {
				res++
				mp[a[i-1]] = true
				a[i-1] = 0
				ok = false
			}
		}
		if ok {
			break
		}
	}
	return res
}
