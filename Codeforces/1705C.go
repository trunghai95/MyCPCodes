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
	var n, c, q int
	var s string
	fmt.Fscan(in, &n, &c, &q, &s)
	length := make([]int64, c)
	ops := make([][]int64, c)
	for i := 0; i < c; i++ {
		ops[i] = make([]int64, 2)
		fmt.Fscan(in, &ops[i][0], &ops[i][1])
		if i == 0 {
			length[i] = int64(len(s)) + ops[i][1] - ops[i][0] + 1
		} else {
			length[i] = length[i-1] + ops[i][1] - ops[i][0] + 1
		}
	}
	// fmt.Println(length)

	var k int64
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &k)
		for k > int64(len(s)) {
			lo := 0
			hi := c - 1
			for lo < hi {
				mid := (lo + hi) / 2
				if length[mid] < k {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			// fmt.Println(k, lo, length[lo])

			k = k - (length[lo] - (ops[lo][1] - ops[lo][0] + 1))
			k = ops[lo][0] + k - 1
		}

		fmt.Fprintln(out, string(s[k-1]))
	}
}
