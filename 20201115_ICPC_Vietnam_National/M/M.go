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

func solve() int {
	var x1, x2, y1, y2 int
	fmt.Fscan(in, &x1, &y1, &x2, &y2)
	xd := abs(x1 - x2)
	yd := abs(y1 - y2)
	res := min(xd, yd) * 2
	d := abs(xd - yd)
	res += (d / 2) * 4
	if d%2 == 1 {
		res++
	}
	return res
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
