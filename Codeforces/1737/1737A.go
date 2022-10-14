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
	var test int
	fmt.Fscan(in, &test)
	for i := 0; i < test; i++ {
		solve()
	}
	defer out.Flush()
}

func solve() {
	var n, k int
	var s string

	fmt.Fscan(in, &n, &k, &s)
	m := n / k
	cnt := make(map[rune]int)
	for _, c := range s {
		cnt[c]++
	}
	// fmt.Println(cnt)

	var res string
	for i := 0; i < k; i++ {
		j := 0
		c := 'a'
		for ; c <= 'z' && j < m; c++ {
			if cnt[c] <= 0 {
				res = res + string(c)
				// fmt.Println(i, j, c)
				break
			}
			// fmt.Println(i, j, c, cnt[c])
			j++
			cnt[c]--
		}
		if j >= m {
			res = res + string(c)
		}
	}
	fmt.Fprintf(out, "%s\n", res)
}
