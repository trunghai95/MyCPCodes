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

	var t int

	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	p := make([]int, n)
	for i := range p {
		fmt.Fscan(in, &p[i])
	}

	sort.Ints(p)
	var res int
	var res1, res2 int
	// case 1: 1 range
	for i := 0; i < n-1; i++ {
		if p[i+1]-p[i] <= 1 {
			continue
		}
		if p[i+1]-p[i]-1 > res {
			res = p[i+1] - p[i] - 1
		}
	}
	if k-p[n-1] > res {
		res = k - p[n-1]
	}
	if p[0]-1 > res {
		res = p[0] - 1
	}

	// case 2: 2 ranges
	for i := 0; i < n-1; i++ {
		d := (p[i+1] - p[i]) / 2
		if d > res1 {
			res1 = d
		}
		if res1 > res2 {
			res1, res2 = res2, res1
		}
	}

	if k-p[n-1] > res1 {
		res1 = k - p[n-1]
		if res1 > res2 {
			res1, res2 = res2, res1
		}
	}
	if p[0]-1 > res1 {
		res1 = p[0] - 1
		if res1 > res2 {
			res1, res2 = res2, res1
		}
	}
	// fmt.Fprintln(out, res, res1, res2)
	if res1+res2 > res {
		res = res1 + res2
	}

	r := float64(res) / float64(k)

	fmt.Fprintf(out, "Case #%d: %.9f\n", tt, r)
}
