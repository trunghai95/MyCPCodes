package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in   = bufio.NewReader(os.Stdin)
	out  = bufio.NewWriter(os.Stdout)
	sqrt = make([]int, 200005)
)

func init() {
	for i := 0; i*i <= 200000; i++ {
		sqrt[i*i+1] = i + 1
	}
	for i := 1; i <= 200000; i++ {
		if sqrt[i] == 0 {
			sqrt[i] = sqrt[i-1]
		}
	}

}

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
	var n int
	fmt.Fscan(in, &n)
	res := make([][]int, 0)
	for n > 2 {
		for i := sqrt[n] + 1; i < n; i++ {
			res = append(res, []int{i, n})
		}
		res = append(res, []int{n, sqrt[n]})
		res = append(res, []int{n, sqrt[n]})
		n = sqrt[n]
	}
	fmt.Fprintln(out, len(res))
	for _, r := range res {
		fmt.Fprintln(out, r[0], r[1])
	}
}
