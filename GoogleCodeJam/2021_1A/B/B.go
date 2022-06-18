package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in     = bufio.NewReader(os.Stdin)
	out    = bufio.NewWriter(os.Stdout)
	primes []int64
	cnt    []int64
)

func init() {
	mark := make([]bool, 500)
	for x := 2; x < 500; x++ {
		if mark[x] {
			continue
		}
		primes = append(primes, int64(x))
		for i := x * x; i < 500; i += x {
			mark[i] = true
		}
	}
	// fmt.Println(primes, len(primes))
}

func main() {
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var m int
	var sum int64
	cnt = make([]int64, len(primes))
	fmt.Fscan(in, &m)
	for i, j := 0, 0; i < m; i++ {
		var p, n int64
		fmt.Fscan(in, &p, &n)
		for primes[j] != p {
			j++
		}
		cnt[j] = n
		sum += n * p
	}

	res := int64(0)
	for score := sum - 2; score >= max(2, sum-30000); score-- {
		if check(score, sum-score) {
			res = score
			break
		}
	}
	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}

func check(score, sum int64) bool {
	for pi := 0; pi < len(primes); pi++ {
		for i := int64(0); i < cnt[pi]; i++ {
			if score%primes[pi] != 0 {
				break
			}
			score = score / primes[pi]
			sum -= primes[pi]
		}
		if score%primes[pi] == 0 {
			return false
		}
	}
	return (score == 1 && sum == 0)
}

func max(x, y int64) int64 {
	if x < y {
		return y
	}
	return x
}
