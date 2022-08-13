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
	var t int
	fmt.Fscan(in, &t)
	for t > 0 {
		t--
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	l := make([]int64, n)
	r := make([]int64, n)
	l[0] = a[0]
	r[n-1] = a[n-1]

	for i := 1; i < n; i++ {
		l[i] = a[i] - l[i-1]
		if l[i-1] < 0 {
			l[i] = -1
		}
	}
	for i := n - 2; i >= 0; i-- {
		r[i] = a[i] - r[i+1]
		if r[i+1] < 0 {
			r[i] = -1
		}
	}

	if check(a) {
		fmt.Fprintln(out, "YES")
		return
	}
	a[0], a[1] = a[1], a[0]
	if check(a) {
		fmt.Fprintln(out, "YES")
		return
	}
	a[0], a[1] = a[1], a[0]
	a[n-1], a[n-2] = a[n-2], a[n-1]
	if check(a) {
		fmt.Fprintln(out, "YES")
		return
	}
	a[n-1], a[n-2] = a[n-2], a[n-1]

	for i := 1; i < n-2; i++ {
		if l[i-1] < 0 || r[i+2] < 0 {
			continue
		}
		if check([]int64{l[i-1], a[i+1], a[i], r[i+2]}) {
			fmt.Fprintln(out, "YES")
			return
		}
	}

	fmt.Fprintln(out, "NO")
}

func check(a []int64) bool {
	// fmt.Fprintln(out, "check", a)
	x := int64(0)
	for _, d := range a {
		x = d - x
		if x < 0 {
			return false
		}
	}
	if x != 0 {
		return false
	}
	for i := len(a) - 1; i >= 0; i-- {
		x = a[i] - x
		if x < 0 {
			return false
		}
	}
	return true
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}
