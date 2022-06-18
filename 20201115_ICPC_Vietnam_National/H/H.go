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

const MOD = 1000000007

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for t > 0 {
		t--
		res := solve()
		fmt.Fprintln(out, res)
	}
}

type mpKey struct {
	c byte
	l int
}

func solve() int64 {
	var n, d int
	fmt.Fscan(in, &n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &w[i])
	}
	fmt.Fscan(in, &d)
	s := make([]string, d)

	mp := make(map[mpKey]int64) // words start with c and len l

	for i := 0; i < d; i++ {
		fmt.Fscan(in, &s[i])
		mp[mpKey{s[i][0], len(s[i])}]++
	}

	var res int64
	for _, chose := range s {
		if len(chose) != n {
			continue
		}
		sum := int64(1)
		last := -1
		for i, c := range chose {
			key := mpKey{byte(c), w[i]}
			if mp[key] == 0 {
				sum = 0
				break
			}
			last = i
			sum = sum * mp[key] % MOD
			mp[key]--
		}

		for i := 0; i < last; i++ {
			key := mpKey{chose[i], w[i]}
			mp[key]++
		}

		res = (res + sum) % MOD
	}
	return res
}
