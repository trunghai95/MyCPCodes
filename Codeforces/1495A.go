package main

import (
	"bufio"
	"fmt"
	"math"
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
	var n, x, y int
	fmt.Fscan(in, &n)
	a := make([]int, 0)
	b := make([]int, 0)
	for i := 0; i < n*2; i++ {
		fmt.Fscan(in, &x, &y)
		if x == 0 {
			a = append(a, abs(y))
		} else {
			b = append(b, abs(x))
		}
	}
	sort.Ints(a)
	sort.Ints(b)
	var res float64
	for i := 0; i < n; i++ {
		res += calc(float64(a[i]), float64(b[i]))
	}
	fmt.Fprintf(out, "%.15f\n", res)
}

func calc(a, b float64) float64 {
	return math.Sqrt(a*a + b*b)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
