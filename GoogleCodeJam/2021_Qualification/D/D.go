package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in      = bufio.NewReader(os.Stdin)
	out     = bufio.NewWriter(os.Stdout)
	n, t, q int
)

func main() {
	defer out.Flush()

	fmt.Fscan(in, &t, &n, &q)

	for i := 1; i <= t; i++ {
		solve()
	}
}

func solve() {
	a := []int{1, 2}
	for i := 3; i <= n; i++ {
		l := 0
		r := len(a) - 1
		ok := false
		for r > l {
			m := (l + r) / 2
			fmt.Fprintf(out, "%d %d %d\n", a[m], a[m+1], i)
			out.Flush()
			var x int
			fmt.Fscan(in, &x)
			if x == i {
				a = append(a, 0)
				copy(a[m+2:], a[m+1:])
				a[m+1] = i
				ok = true
				break
			} else if x == a[m] {
				r = m
			} else {
				l = m + 1
			}
		}
		if !ok {
			if r == len(a)-1 {
				a = append(a, i)
			} else {
				a = append(a, 0)
				copy(a[1:], a[0:])
				a[0] = i
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", a[i])
	}
	fmt.Fprintln(out)
	out.Flush()
	var x int
	fmt.Fscan(in, &x)
}
