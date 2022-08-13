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
		fmt.Fprintln(out, solve())
	}
}

func solve() int64 {
	var x, n, m int
	fmt.Fscan(in, &n, &m)
	cnt := make([]int, m)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x)
		cnt[x-1]++
	}
	c := make([]int64, m)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &c[i])
	}
	ptr := 0
	res := int64(0)

	for i := m - 1; i >= 0; i-- {
		for cnt[i] > 0 && ptr < i {
			res += c[ptr]
			ptr++
			cnt[i]--
		}
		if cnt[i] > 0 {
			res += c[i] * int64(cnt[i])
		}
	}
	return res
}
