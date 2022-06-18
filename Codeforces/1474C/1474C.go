package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	n <<= 1
	a := make([]int, n)
	cnt := make(map[int]int)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		cnt[a[i]]++
	}
	sort.Ints(a)
	for i := 0; i < n-1; i++ {
		if solve1(a, cnt, a[i]) {
			return
		}
	}
	fmt.Fprintln(out, "NO")
}

func solve1(a []int, cnt map[int]int, pp int) bool {
	res := make([][]int, 0)
	n := len(a)
	cc := make(map[int]int)
	cc[a[n-1]]++
	cc[pp]++
	i := n - 2
	x := a[n-1]
	res = append(res, []int{x, pp})
	sum := x + pp
	for i > 0 {
		if cnt[a[i]] <= cc[a[i]] {
			i--
			continue
		}
		cc[a[i]]++
		if cnt[x-a[i]] <= cc[x-a[i]] {
			return false
		}
		res = append(res, []int{a[i], x - a[i]})
		cc[x-a[i]]++
		x = a[i]
		i--
	}
	fmt.Fprintln(out, "YES")
	fmt.Fprintln(out, sum)
	for _, r := range res {
		fmt.Fprintln(out, r[0], r[1])
	}
	return true
}
