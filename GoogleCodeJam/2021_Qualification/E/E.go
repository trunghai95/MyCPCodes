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

type SortQ []int

func (s SortQ) Len() int           { return len(s) }
func (s SortQ) Less(x, y int) bool { return cnt[s[x]] > cnt[s[y]] }
func (s SortQ) Swap(x, y int)      { s[x], s[y] = s[y], s[x] }

func main() {
	defer out.Flush()

	var t, p int
	fmt.Fscan(in, &t, &p)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	s := make([]string, 100)
	score := make([]int, 100)
	cnt = make([]int, 10000)
	for i := 0; i < 100; i++ {
		fmt.Fscan(in, &s[i])
		for j, c := range s[i] {
			if c == '1' {
				cnt[j]++
				score[i]++
			}
		}
	}

	q := make([]int, 10000)
	for i := range q {
		q[i] = i
	}

	sort.Sort(SortQ(q))
	qdif := make([]int, 10000)
	for i := 0; i < 10000; i++ {
		qdif[q[i]] = i
	}
	// for i := 0; i < 10000; i++ {
	// 	fmt.Fprintf(out, "%d ", q[i])
	// }
	// fmt.Fprintln(out)
	// for i := 0; i < 10000; i++ {
	// 	fmt.Fprintf(out, "Q%d: cnt[%d] dif[%d]\n", i, cnt[i], qdif[i])
	// }

	res := -1
	rescnt := 1000000000

	for i := 0; i < 100; i++ {
		cc := 0
		for j := 0; j < 10000; j++ {
			for k := j + 1; k < 10000; k++ {
				if s[i][j] == s[i][k] {
					continue
				}
				if s[i][j] == '1' && qdif[k] > qdif[j] {
					cc++
				} else if s[i][j] == '0' && qdif[j] > qdif[k] {
					cc++
				}
			}
			// if (s[i][j] == '0' && qdif[j] < score[i]-10) || (s[i][j] == '1' && qdif[j] > score[i]+10) {
			// 	cc++
			// }
		}
		fmt.Fprintf(out, "%d: %d %d\n", i, score[i], cc)
		if cc < rescnt {
			rescnt = cc
			res = i
		}
	}
	fmt.Fprintf(out, "Case #%d: %d\n", tt, res+1)
}
