package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in     = bufio.NewReader(os.Stdin)
	out    = bufio.NewWriter(os.Stdout)
	primes = sieve()
)

func sieve() []int {
	res := make([]int, 0)
	np := make([]bool, 1000)

	for i := 2; i < 1000; i++ {
		if !np[i] {
			res = append(res, i)
			for j := i * i; j < 1000; j += i {
				np[j] = true
			}
		}
	}
	// fmt.Println(res)
	return res
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
	var a, n, m int
	var w int64
	s := make(map[int]int)
	fmt.Fscan(in, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a)
		a = foo(a)
		s[a]++
	}
	// fmt.Fprintln(out, s)
	var mx, sum int
	for val, sz := range s {
		if sz > mx {
			mx = sz
		}
		if val == 1 || sz%2 == 0 {
			sum += sz
		}
	}
	if mx > sum {
		sum = mx
	}

	fmt.Fscan(in, &m)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &w)
		if w == 0 {
			fmt.Fprintln(out, mx)
		} else {
			fmt.Fprintln(out, sum)
		}
	}
}

func foo(a int) int {
	for _, p := range primes {
		if p > a {
			break
		}
		ok := false
		for a%p == 0 {
			ok = !ok
			a /= p
		}
		if ok {
			a = a * p
		}
	}
	// fmt.Println(a)
	return a
}
