package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in   = bufio.NewReader(os.Stdin)
	out  = bufio.NewWriter(os.Stdout)
	n, k int
	arr  [][]int
	dir  = [][]int{
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	}
)

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(tt int) {
	fmt.Fscan(in, &n, &k)

	arr = fillMatrix(n)
	target := n*n - 1 - k

	fmt.Fprintf(out, "Case #%d: ", tt)
	if try(0, 0, 0, target, 0, [][]int{}) == false {
		fmt.Fprintf(out, "IMPOSSIBLE\n")
	}
}

func try(x, y, sum, target, cnt int, res [][]int) bool {
	if cnt >= k {
		return false
	}
	for d := 0; d < 4; d++ {
		xx := x + dir[d][0]
		yy := y + dir[d][1]

		if xx >= n || xx < 0 || yy >= n || yy < 0 || arr[xx][yy] < arr[x][y] {
			continue
		}

		r := arr[xx][yy] - arr[x][y] - 1
		if sum+r > target {
			continue
		}

		newRes := res
		if r > 1 {
			newRes = append(res, []int{arr[x][y], arr[xx][yy]})
		}

		if sum+r == target {
			fmt.Fprintf(out, "%d\n", len(newRes))
			for _, p := range newRes {
				fmt.Fprintf(out, "%d %d\n", p[0], p[1])
			}
			return true
		}

		if try(xx, yy, sum+r, target, cnt+1, newRes) {
			return true
		}
	}

	return false
}

func fillMatrix(n int) [][]int {
	d := 0

	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}
	x := 0
	y := 0
	i := 1
	target := n * n
	for i <= target {
		// fmt.Fprintln(out, x, y, i)
		res[x][y] = i
		xx := x + dir[d][0]
		yy := y + dir[d][1]
		if xx >= n || xx < 0 || yy >= n || yy < 0 || res[xx][yy] > 0 {
			d = (d + 1) % 4
			xx = x + dir[d][0]
			yy = y + dir[d][1]
		}
		x = xx
		y = yy
		i++
	}
	// fmt.Fprintln(out, res)
	return res
}
