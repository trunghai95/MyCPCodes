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
	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	if n == 1 {
		for j := 0; j < m; j++ {
			fmt.Fprint(out, "X")
		}
		fmt.Fprintln(out)
		return
	}

	for j := 0; j < m; j++ {
		a[1][j] = 'X'
	}
	for i := 4; i < n; i += 3 {
		nf := true
		tf := -1
		for j := 0; j < m; j++ {
			a[i][j] = 'X'
			if a[i-1][j] == 'X' && a[i-2][j] == 'X' {
				nf = false
			} else if a[i-1][j] == 'X' || a[i-2][j] == 'X' {
				if tf < 0 {
					tf = j
				}
			}
		}
		if nf {
			a[i-1][tf] = 'X'
			a[i-2][tf] = 'X'
		}
	}
	if n > 1 && n%3 == 1 {
		for j := 0; j < m; j++ {
			if a[n-1][j] == 'X' {
				a[n-2][j] = 'X'
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fprintln(out, string(a[i]))
	}
}
