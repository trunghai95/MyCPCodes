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
	primes := listPrimes()

	var test, n int
	fmt.Fscan(in, &test)
	res := make([]int, test)
	for i := 0; i < test; i++ {
		fmt.Fscan(in, &n)
		first, second := -1, -1
		for _, p := range primes {
			if p >= n {
				break
			}
			if n%p == 0 {
				if first == -1 {
					first = p
				} else {
					second = p
					break
				}
			}
		}
		if second == -1 {
			first = -1
		}
		res[i] = second
		fmt.Fprintf(out, "%d ", first)
	}
	fmt.Fprintln(out)
	for _, x := range res {
		fmt.Fprintf(out, "%d ", x)
	}
	fmt.Fprintln(out)
}

func listPrimes() []int {
	bound := 3200
	mark := make([]bool, bound)
	res := make([]int, 0)
	for i := 2; i < bound; i++ {
		if mark[i] {
			continue
		}
		res = append(res, i)
		for j := i * i; j < bound; j += i {
			mark[j] = true
		}
	}
	return res
}
