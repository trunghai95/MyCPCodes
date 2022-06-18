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

	for {
		res := solve()
		if res == -1 {
			return
		}
		fmt.Fprintln(out, res)
	}
}

type Point struct {
	x int64
	y int64
}

func solve() int {
	var n int
	fmt.Fscan(in, &n)
	if n == 0 {
		return -1
	}
	p := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i].x, &p[i].y)
	}
	res := 0
	for i1 := 0; i1 < n; i1++ {
		for i2 := i1 + 1; i2 < n; i2++ {
			for i3 := i2 + 1; i3 < n; i3++ {
				for i4 := i3 + 1; i4 < n; i4++ {
					if check(p[i1], p[i2], p[i3], p[i4]) {
						res++
					}
				}
			}
		}
	}
	return res
}

func check(p1, p2, p3, p4 Point) bool {
	return !isInTri(p1, p2, p3, p4) && !isInTri(p2, p1, p3, p4) && !isInTri(p3, p1, p2, p4) && !isInTri(p4, p1, p2, p3)
}

func isInTri(p, a, b, c Point) bool {
	return area2(a, b, c) == area2(p, a, b)+area2(p, b, c)+area2(p, c, a)
}

func area2(a, b, c Point) int64 {
	return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
