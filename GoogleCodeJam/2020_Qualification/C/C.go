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

type Info struct {
	time int
	tp   int // 0: start, 1: end
	idx  int
}

type InfoSort []Info

func (x InfoSort) Len() int      { return len(x) }
func (x InfoSort) Swap(i, j int) { x[i], x[j] = x[j], x[i] }
func (x InfoSort) Less(i, j int) bool {
	if x[i].time == x[j].time {
		return x[i].tp > x[j].tp
	}
	return x[i].time < x[j].time
}

func solve(t int) {
	var n, s, e int
	arr := make(InfoSort, 0)
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &s, &e)
		arr = append(arr, Info{s, 0, i}, Info{e, 1, i})
	}
	sort.Sort(arr)
	// fmt.Println(arr)

	res := make([]byte, n)
	var busyC, busyJ bool
	for _, x := range arr {
		if x.tp == 0 {
			if !busyC {
				res[x.idx] = 'C'
				busyC = true
				// fmt.Printf("assign %v to C\n", x.idx)
			} else if !busyJ {
				res[x.idx] = 'J'
				busyJ = true
				// fmt.Printf("assign %v to J\n", x.idx)
			} else {
				fmt.Printf("Case #%v: IMPOSSIBLE\n", t)
				return
			}
		} else {
			if res[x.idx] == 'C' {
				busyC = false
				// fmt.Printf("release %v from C\n", x.idx)
			} else {
				busyJ = false
				// fmt.Printf("release %v from J\n", x.idx)
			}
		}
	}
	fmt.Printf("Case #%v: %s\n", t, string(res))
}
