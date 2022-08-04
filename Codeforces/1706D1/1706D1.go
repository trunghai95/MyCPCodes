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

	var test int
	fmt.Fscan(in, &test)
	for i := 0; i < test; i++ {
		fmt.Fprintln(out, solve())
	}
}

func solve() int {
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	lo := 0
	hi := 3000
	for lo < hi {
		mid := (lo + hi) / 2
		ok := false

		for x := 0; x <= 3000-mid; x++ {
			ok2 := true
			for i := 0; i < n; i++ {
				if x > a[i] {
					ok2 = false
					break
				}
				if x == 0 {
					// fmt.Println(a[i], k)
					if k <= a[i] {
						ok2 = false
						break
					}
				} else {
					p := a[i] / x
					fmt.Println(".", x, a[i], p)
					for a[i]/p > mid+x && p <= k {
						p++
					}
					fmt.Println("..", x, a[i], p)
					if p > k || a[i]/p < x {
						ok2 = false
						break
					}
				}
			}
			if ok2 {
				fmt.Println("...", x, mid+x)
				ok = true
				break
			}
		}

		fmt.Println(lo, hi, mid, ok)

		if ok {
			hi = mid
		} else {
			lo = mid + 1
		}
	}

	return lo
}
