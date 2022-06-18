package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var str string
	fmt.Fscan(in, &str)
	if len(str) > 16 {
		return
	}
	s, _ := strconv.ParseInt(str, 2, 32)
	fmt.Fscan(in, &str)
	if len(str) > 16 {
		return
	}
	e, _ := strconv.ParseInt(str, 2, 32)
	// fmt.Fprintln(out, s, e)

	dist := make(map[int64]int)
	dist[s] = 0
	queue := []int64{s}

	for len(queue) > 0 {
		// fmt.Fprintln(out, queue)
		x := queue[0]
		queue = queue[1:]
		if x == e {
			fmt.Fprintf(out, "Case #%d: %d\n", tt, dist[e])
			return
		}

		y := x << 1
		if _, ok := dist[y]; !ok && y < (1<<10) {
			dist[y] = dist[x] + 1
			queue = append(queue, y)
		}
		y = not(x)
		if _, ok := dist[y]; !ok {
			dist[y] = dist[x] + 1
			queue = append(queue, y)
		}
	}
	fmt.Fprintf(out, "Case #%d: IMPOSSIBLE\n", tt)
}

func not(x int64) int64 {
	mask := int64(1)
	for mask < x {
		mask = (mask << 1) | 1
	}
	y := mask &^ x
	// fmt.Fprintln(out, "not", x, y)
	return y
}
