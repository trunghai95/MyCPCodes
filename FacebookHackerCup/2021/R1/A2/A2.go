package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	mod = int64(1000000007)
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
	var n int
	var s string

	fmt.Fscan(in, &n, &s)

	// TODO...
	f := make([]int64, n)
	lastX, lastO := -1, -1
	if s[0] == 'X' {
		lastX = 0
	} else if s[0] == 'O' {
		lastO = 0
	}
	res := int64(0)

	for i := 1; i < n; i++ {
		if s[i] == 'F' {
			f[i] = f[i-1]
		} else if s[i] == 'O' {
			if lastX == -1 {
				f[i] = 0
			} else {
				f[i] = (f[lastX] + int64(lastX) + 1) % mod
			}
			lastO = i
		} else {
			if lastO == -1 {
				f[i] = 0
			} else {
				f[i] = (f[lastO] + int64(lastO) + 1) % mod
			}
			lastX = i
		}
		res = (res + f[i]) % mod
	}

	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}