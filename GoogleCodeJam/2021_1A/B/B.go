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

	res := tryy(sum, 1, 0, 0)
	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}

func tryy(sum, prod, pi, pcnt int64) int64 {
	if prod > sum {
		return 0
	}
	if prod == sum {
		return sum
	}
	res := int64(0)
	if pcnt+1 <= cnt[pi] && prod <= (sum-primes[pi])/primes[pi] {
		res = max(res, tryy(sum-primes[pi], prod*primes[pi], pi, pcnt+1))
	}
	for i := pi + 1; i < int64(len(primes)); i++ {
		if cnt[i] > 0 && prod <= (sum-primes[i])/primes[i] {
			res = max(res, tryy(sum-primes[i], prod*primes[i], i, 1))
		}
	}
	return res
}

func max(x, y int64) int64 {
	if x < y {
		return y
	}
	return x
}
