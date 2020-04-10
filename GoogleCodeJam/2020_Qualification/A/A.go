package main

import (
	"fmt"
)

func solve(t int) {
	var n, cntr, cntc, trace int
	fmt.Scanf("%d", &n)
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = make([]int, n)
		mp := make(map[int]bool)
		ok := 0
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &m[i][j])
			if mp[m[i][j]] {
				ok = 1
			}
			mp[m[i][j]] = true
		}
		trace += m[i][i]
		cntr += ok
	}
	for j := 0; j < n; j++ {
		mp := make(map[int]bool)
		ok := 0
		for i := 0; i < n; i++ {
			if mp[m[i][j]] {
				ok = 1
			}
			mp[m[i][j]] = true
		}
		cntc += ok
	}

	fmt.Printf("Case #%v: %v %v %v\n", t, trace, cntr, cntc)
}

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}
