package main

import (
	"fmt"
)

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(t int) {
	var l, r int64
	fmt.Scanf("%d %d", &l, &r)
	// rand.Seed(time.Now().Unix())
	// l = rand.Int63()%100 + 1
	// r = rand.Int63()%100 + 1
	// l = 85
	// r = 88
	// c1, c2 := l, r
	// r1, r2, r3 := bf(int(l), int(r))
	fmt.Printf("Case #%d: ", t)
	var start int64
	if l >= r {
		start = calcStart(l, r, 0)
		// fmt.Println(start)
		l -= sum(start - 1)
		if l >= r {
			if l < start {
				fmt.Println(start-1, l, r)
				return
			}
			l -= start
			start++
		}
	} else {
		start = calcStart(r, l, 1)
		// fmt.Println(start)
		r -= sum(start - 1)
		if l < start {
			fmt.Println(start-1, l, r)
			return
		}
		l -= start
		start++
	}
	// fmt.Println(l, r, start)
	fmt.Println(calcRes(l, r, start))
	// r4, r5, r6 := calcRes(l, r, start)
	// if r1 != int(r4) || r2 != int(r5) || r3 != int(r6) {
	// 	fmt.Println("wrong", c1, c2, r1, r2, r3, r4, r5, r6)
	// 	os.Exit(0)
	// }
}

func calcRes(l, r, start int64) (int64, int64, int64) {
	if r < start {
		return start - 1, l, r
	}
	lo := start
	hi := int64(2000000000)
	for lo < hi {
		mid := (lo+hi)/2 + 1
		if (start % 2) != 0 {
			// fmt.Println("odd", lo, hi, mid, r-(sumodd(mid)-sumodd(start-1)), l-(sumeven(mid)-sumeven(start-1)))
			if (r-(sumodd(mid)-sumodd(start-1)) < 0) || (l-(sumeven(mid)-sumeven(start-1)) < 0) {
				hi = mid - 1
			} else {
				lo = mid
			}
		} else {
			// fmt.Println("even", mid, l-(sumodd(mid)-sumodd(start-1)), r-(sumeven(mid)-sumeven(start-1)))
			if (l-(sumodd(mid)-sumodd(start-1)) < 0) || (r-(sumeven(mid)-sumeven(start-1)) < 0) {
				hi = mid - 1
			} else {
				lo = mid
			}
		}
	}
	// fmt.Println(lo, hi)
	if (start % 2) != 0 {
		return lo, l - (sumeven(lo) - sumeven(start-1)), r - (sumodd(lo) - sumodd(start-1))
	}
	return lo, l - (sumodd(lo) - sumodd(start-1)), r - (sumeven(lo) - sumeven(start-1))
}

func calcStart(large, small, ep int64) int64 {
	lo := int64(1)
	hi := int64(2000000000)
	for lo < hi {
		mid := (lo + hi) / 2
		// fmt.Println(lo, hi, mid, large-sum(mid)-ep, small)
		if large-sum(mid)-ep < small {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	if large-sum(lo) < 0 {
		lo--
	}
	return lo + 1
}

func sum(x int64) int64 {
	if x%2 == 0 {
		return x / 2 * (x + 1)
	}
	return (x + 1) / 2 * x
}

func sumodd(x int64) int64 {
	res := (x + 1) / 2
	return res * res
}

func sumeven(x int64) int64 {
	res := x / 2
	return res * (res + 1)
}

// func bf(l, r int) (int, int, int) {
// 	var i = 1
// 	for {
// 		if l >= r {
// 			l -= i
// 		} else {
// 			r -= i
// 		}
// 		i++
// 		if i > r && i > l {
// 			break
// 		}
// 	}
// 	return i - 1, l, r
// }
