package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	max = 1000000
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
	fmt.Fprintf(out, "Case #%d: ", tt)

	c := make([][]int, 3)
	for i := 0; i < 3; i++ {
		c[i] = make([]int, 4)
		for j := 0; j < 4; j++ {
			fmt.Fscan(in, &c[i][j])
		}
	}

	res := make([]int, 4)
	sum := 0
	for j := 0; j < 4; j++ {
		res[j] = max
		for i := 0; i < 3; i++ {
			if c[i][j] < res[j] {
				res[j] = c[i][j]
			}
		}
		sum += res[j]
	}

	// fmt.Fprintln(out, c, res, sum)
	if sum < max {
		fmt.Fprintf(out, "IMPOSSIBLE\n")
		return
	}

	for j := 0; j < 4 && sum > max; j++ {
		if res[j] > sum-max {
			res[j] -= sum - max
			sum = max
		} else {
			sum -= res[j]
			res[j] = 0
		}
	}

	fmt.Fprintf(out, "%d %d %d %d\n", res[0], res[1], res[2], res[3])
}
