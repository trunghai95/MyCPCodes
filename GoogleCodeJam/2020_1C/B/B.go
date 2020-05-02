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

type cntstruct struct {
	val rune
	cnt int
}

type cntsort []cntstruct

func (c cntsort) Len() int           { return len(c) }
func (c cntsort) Swap(x, y int)      { c[x], c[y] = c[y], c[x] }
func (c cntsort) Less(x, y int) bool { return c[x].cnt < c[y].cnt }

func solve(t int) {
	var u int
	q := make([]string, 10000)
	r := make([]string, 10000)
	res := make([]rune, 10)
	cnt := make(map[rune]int)
	fmt.Scanf("%d", &u)
	for i := 0; i < 10000; i++ {
		fmt.Scanf("%s %s", &q[i], &r[i])
		for j, c := range r[i] {
			_, ok := cnt[c]

			if j == 0 {
				cnt[c]++
			} else if !ok {
				cnt[c] = 0
			}
		}
	}

	c := make([]cntstruct, 0)
	for k, v := range cnt {
		c = append(c, cntstruct{k, v})
	}
	sort.Sort(cntsort(c))
	res[0] = c[0].val
	for i := 1; i < 10; i++ {
		res[10-i] = c[i].val
	}

	fmt.Printf("Case #%d: %s\n", t, string(res))
}
