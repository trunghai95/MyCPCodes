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
	var n, m, u, v int
	fmt.Fscan(in, &n, &m)

	adj := make([][]int, n+1)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	mark := make([]int, n+1)
	mark[1] = 1
	q := []int{1}

	for len(q) > 0 {
		c := q[0]
		q = q[1:]

		if mark[c] == 1 {
			for _, d := range adj[c] {
				if mark[d] != 2 {
					mark[d] = 2
					q = append(q, d)
				}
			}
		} else {
			for _, d := range adj[c] {
				if mark[d] == 0 {
					mark[d] = 1
					q = append(q, d)
				}
			}
		}
	}

	ok := true
	res := []int{}
	for i := 1; i <= n; i++ {
		if mark[i] == 0 {
			ok = false
			break
		}
		if mark[i] == 1 {
			res = append(res, i)
		}
	}

	if !ok {
		fmt.Fprintln(out, "NO")
	} else {
		fmt.Fprintf(out, "YES\n%d\n", len(res))
		for _, i := range res {
			fmt.Fprintf(out, "%d ", i)
		}
		fmt.Fprintf(out, "\n")
	}
}
