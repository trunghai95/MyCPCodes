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
	var n int
	fmt.Fscan(in, &n)

	a := make([]string, n)
	c1 := make([]int, n)
	c2 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		for j := range a[i] {
			if a[i][j] == '.' {
				if c1[i] != -1 {
					c1[i]++
				}
				if c2[j] != -1 {
					c2[j]++
				}
			} else if a[i][j] == 'O' {
				c1[i] = -1
				c2[j] = -1
			}
		}
	}

	res := -1
	cnt := -1

	for _, c := range c1 {
		if c == -1 {
			continue
		}
		if res == -1 || c < res {
			res = c
			cnt = 1
		} else if c == res {
			cnt++
		}
	}
	for _, c := range c2 {
		if c == -1 {
			continue
		}
		if res == -1 || c < res {
			res = c
			cnt = 1
		} else if c == res {
			cnt++
		}
	}

	fmt.Fprintf(out, "Case #%d: ", tt)
	if res == -1 {
		fmt.Fprintf(out, "Impossible\n")
		return
	}
	if res == 1 {
		for i := range c1 {
			if c1[i] != 1 {
				continue
			}
			for j := range a[i] {
				if a[i][j] == '.' {
					if c2[j] == 1 {
						cnt--
					}
					break
				}
			}
		}
	}
	fmt.Fprintf(out, "%d %d\n", res, cnt)
}
