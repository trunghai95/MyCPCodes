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

	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var s string
	fmt.Fscan(in, &s)
	n := len(s)
	var res string
	for i := 0; i <= n; i++ {
		t := s[:i]
		if i == n {
			t = s
		}
		var x int64
		fmt.Sscan(t, &x)
		if i == 0 {
			x = 1
		}
		for j := int64(0); j <= 10000; j++ {
			t = build(x+j, s)
			if res == "" || larger(res, t) {
				res = t
			}
		}
	}
	fmt.Fprintf(out, "Case #%d: %s\n", tt, res)
}

func build(x int64, s string) string {
	// fmt.Fprintln(out, "build", x, s)
	t := fmt.Sprint(x)
	x++
	t = t + fmt.Sprint(x)
	for !larger(t, s) {
		x++
		t = t + fmt.Sprint(x)
	}
	// fmt.Fprintln(out, t)
	return t
}

func larger(s, t string) bool {
	if len(s) < len(t) {
		return false
	}
	if len(s) > len(t) {
		return true
	}

	for i := range s {
		if s[i] > t[i] {
			return true
		}
		if s[i] < t[i] {
			return false
		}
	}
	return false
}
