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

func solve() int64 {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	// fmt.Println(a)

	lo := 0
	for lo < n && a[lo] == 0 {
		lo++
	}
	hi := lo + 1
	var cnt int64
	for lo < n-1 {
		// fmt.Println(lo, hi)
		for hi < n-1 && a[hi] > 0 {
			hi++
		}
		if hi == n-1 {
			cnt += a[lo]
			a[hi] += a[lo]
			a[lo] = 0
			lo++
		} else {
			cnt++
			a[hi]++
			a[lo]--
			for lo < n-1 && a[lo] == 0 {
				lo++
			}
			if lo == n-1 {
				break
			}
		}
	}
	return cnt
}
