package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in    = bufio.NewReader(os.Stdin)
	out   = bufio.NewWriter(os.Stdout)
	v     []int64
	n     int64
	facto []int64
	mod   = int64(1000000007)
	maxn  = 100000
)

func init() {
	facto = make([]int64, maxn+1)
	facto[0] = 1
	for i := 1; i <= maxn; i++ {
		facto[i] = facto[i-1] * int64(i) % mod
	}
}

func inv(x int64) int64 {
	return pow(x, mod-2)
}

func pow(x, y int64) int64 {
	if y == 0 {
		return 1
	}

	res := pow(x, y/2)
	res = res * res % mod
	if y%2 == 1 {
		res = res * x % mod
	}
	return res
}

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	fmt.Fscan(in, &n)
	v = make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		fmt.Fscan(in, &v[i])
	}

	fmt.Fprintf(out, "Case #%d: %d\n", tt, try(1, n, 1))
}

func try(lo, hi, b int64) int64 {
	if hi < lo {
		// fmt.Fprintln(out, lo, hi, b, 1)
		return 1
	}
	var m int64
	for i := hi; i >= lo; i-- {
		if v[i]-b == 0 {
			m = i
			break
		}
	}
	if m == 0 {
		return 0
	}
	rr := (c(m-lo, hi-lo) * try(lo, m-1, b) % mod) * try(m+1, hi, b+1) % mod
	// fmt.Fprintln(out, lo, hi, b, rr)
	return rr
}

func c(x, y int64) int64 {
	rr := (facto[y] * inv(facto[x]) % mod) * inv(facto[y-x]) % mod
	return rr
}
