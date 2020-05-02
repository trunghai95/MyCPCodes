package main

import (
	"fmt"
	"sort"
)

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

type IntSort []int

func (s IntSort) Len() int           { return len(s) }
func (s IntSort) Swap(x, y int)      { s[x], s[y] = s[y], s[x] }
func (s IntSort) Less(x, y int) bool { return s[x] < s[y] }

func solve(t int) {
	var n, d int
	fmt.Scanf("%d %d", &n, &d)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	sort.Sort(IntSort(a))
	fmt.Printf("Case #%d: ", t)
	if d == 2 {
		fmt.Println(solve2(n, a))
	} else { // d == 3
		fmt.Println(solve3(n, a))
	}
}

func solve2(n int, a []int) int {
	if n == 1 {
		return 1
	}
	mp := make(map[int]bool)
	for _, x := range a {
		if mp[x] {
			return 0
		}
		mp[x] = true
	}
	return 1
}

func solve3(n int, a []int) int {
	if n == 1 {
		return 2
	}
	res := 2
	mp := make(map[int]bool)
	mp[a[0]] = true
	for i := 1; i < n; i++ {
		if a[i] == a[i-1] {
			if i < n-1 && a[i] == a[i+1] {
				res = 0
			}
			if i < n-1 {
				res = min(res, 1)
			}
		}
		mp[a[i]] = true
		if a[i]%2 == 0 && mp[a[i]/2] {
			res = min(res, 1)
		}
	}
	return res
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
