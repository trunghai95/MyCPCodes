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
	var n, m, x int
	fmt.Fscan(in, &n, &m)
	s := []byte{}
	for i := 0; i < m; i++ {
		s = append(s, 'B')
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x)
		x--
		y := m - 1 - x
		if x > y {
			x, y = y, x
		}

		if s[x] == 'B' {
			s[x] = 'A'
		} else {
			s[y] = 'A'
		}
	}
	fmt.Fprintln(out, string(s))
}
