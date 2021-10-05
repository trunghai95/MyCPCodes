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
	cnt []int
)

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

type IntSort []int

func (s IntSort) Len() int           { return len(s) }
func (s IntSort) Less(i, j int) bool { return cnt[i] < cnt[j] }
func (s IntSort) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func solve(tt int) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	s := make([]int, m)
	p := make([]int, n)
	res := 0
	cnt = make([]int, m)
	mp := make(map[int][]int)

	for i := 0; i < m; i++ {
		fmt.Fscan(in, &s[i])
		mp[s[i]] = append(mp[s[i]], i)
	}
	for i := 0; i < n; i++ {
		for k := range mp {
			sort.Sort(IntSort(mp[k]))
		}
		p = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &p[j])
		}
		mark := make([]bool, m)
		for j := 0; j < m; j++ {
			if len(mp[p[j]]) > 0 {
				mark[j] = true
				ii := mp[p[j]][len(mp[p[j]])-1]
				mp[p[j]] = mp[p[j]][:len(mp[p[j]])-1]

				s[ii] = p[j]
			}
		}

		// fmt.Println(p, mark, mp)

		j := 0
		for k := range mp {
			if len(mp[k]) == 0 {
				continue
			}
			for _, x := range mp[k] {
				for j < m && mark[j] == true {
					j++
				}
				s[x] = p[j]
				cnt[x]++
				j++
			}
		}

		mp = make(map[int][]int)
		for i := 0; i < m; i++ {
			mp[s[i]] = append(mp[s[i]], i)
		}
		// fmt.Println(s, mp)
	}

	for i := 0; i < m; i++ {
		if cnt[i] > 0 {
			res += cnt[i] - 1
		}
	}

	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}
