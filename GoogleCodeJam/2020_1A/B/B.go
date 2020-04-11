package main

import "fmt"

var pow2 []int

func main() {
	pow2 = make([]int, 31)
	pow2[0] = 1
	for i := 1; i <= 30; i++ {
		pow2[i] = pow2[i-1] * 2
	}
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(t int) {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Printf("Case #%v:\n", t)
	if n <= 8 {
		printBase(n)
		return
	}
	rows := make([]int, 0)
	last := find(n, 0)
	// fmt.Println(last)
	rows = append(rows, last)
	n -= pow2[last-1]
	for n > 8 {
		// fmt.Println(n, last)
		r := find(n, last)
		n -= pow2[r-1] + (last - r - 1)
		rows = append(rows, r)
		last = r
	}
	fmt.Println(rows, n)
	cr := printBase(n)
	rev := false
	for _, r := range rows {
		for cr < r {
			if rev {
				fmt.Printf("%d %d\n", cr, cr)
			} else {
				fmt.Printf("%d %d\n", cr, 1)
			}
			cr++
		}
		if rev {
			for j := r; j >= 1; j-- {
				fmt.Printf("%d %d\n", r, j)
			}
		} else {
			for j := 1; j <= r; j++ {
				fmt.Printf("%d %d\n", r, j)
			}
		}
		rev = !rev
	}
}

func printBase(n int) int {
	switch n {
	case 1:
		fmt.Printf("1 1\n")
		return 2
	case 2:
		fmt.Printf("1 1\n2 1\n")
		return 3
	case 3:
		fmt.Printf("1 1\n2 2\n2 1\n")
		return 3
	case 4:
		fmt.Printf("1 1\n2 1\n3 2\n")
		return 3
	case 5:
		fmt.Printf("1 1\n2 1\n3 2\n3 1\n")
		return 4
	case 6:
		fmt.Printf("1 1\n2 1\n2 2\n3 2\n3 1\n")
		return 4
	case 7:
		fmt.Printf("1 1\n2 1\n2 2\n3 3\n3 2\n3 1\n")
		return 4
	case 8:
		fmt.Printf("1 1\n2 1\n2 2\n3 3\n3 2\n3 1\n4 1\n")
		return 5
	}
	return 0
}

func printBase2(n int) int {
	switch n {
	case 1:
		fmt.Printf("1 1\n2 2\n")
		return 2
	case 2:
		fmt.Printf("1 1\n2 1\n3 2\n")
		return 3
	case 3:
		fmt.Printf("1 1\n2 1\n2 2\n3 2\n")
		return 3
	case 4:
		fmt.Printf("1 1\n2 1\n2 2\n3 3\n3 2\n")
		return 3
	}
	return 0
}

func find(n, last int) int {
	lo := 4
	hi := 31
	for lo < hi {
		mid := (lo+hi)/2 + 1
		val := 0
		if last > 0 {
			val = last - mid - 1
		}
		// fmt.Println(mid, last, val, pow2[mid-1]+mid-1+val, n)
		if (last == 0 || mid < last) && pow2[mid-1]+mid-1+val <= n {
			lo = mid
		} else {
			hi = mid - 1
		}
	}
	return lo
}
