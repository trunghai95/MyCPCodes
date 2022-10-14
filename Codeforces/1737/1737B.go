package main

import (
	"bufio"
	"fmt"
	"math"
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

func solve() int64 {
	var l, r int64
	fmt.Fscan(in, &l, &r)
	if l == r {
		x := int64(math.Sqrt(float64(l)))
		if x*x > l {
			x--
		}
		if l%x == 0 {
			return 1
		}
		return 0
	}

	lo := int64(math.Sqrt(float64(l)))
	hi := int64(math.Sqrt(float64(r)))

	if lo*lo > l {
		lo--
	}
	if hi*hi > r {
		hi--
	}
	hi++

	// fmt.Println(lo, hi)

	if hi-lo == 1 {
		res := int64(0)
		for i := lo * lo; i <= hi*hi; i += lo {
			if i >= l && i <= r {
				res++
			}
		}
		return res
	}
	res := (hi - lo - 2) * 3
	mid := lo + 1
	for i := lo * lo; i < mid*mid; i += lo {
		if i >= l && i <= r {
			res++
		}
	}
	mid = hi - 1
	for i := mid * mid; i <= hi*hi; i += mid {
		if i >= l && i <= r {
			res++
		}
	}
	return res
}
