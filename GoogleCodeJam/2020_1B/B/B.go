package main

import (
	"fmt"
)

const BOUND = 1000000000

func main() {
	var test, a, b int
	fmt.Scanf("%d %d %d", &test, &a, &b)
	for i := 1; i <= test; i++ {
		solve(i, a, b)
	}
}

func solve(t, a, b int) {
	jump := a / 2
	var px, py int
	for x := -BOUND + jump; x <= BOUND; x += jump {
		ok := false
		for y := -BOUND + jump; y <= BOUND; y += jump {
			s := check(x, y)
			if s == "CENTER" {
				return
			}
			if s == "HIT" {
				px, py = x, y
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}

	x1, ok := findX1(px, py)
	if ok {
		return
	}
	x2, ok := findX2(px, py)
	if ok {
		return
	}
	y1, ok := findY1(px, py)
	if ok {
		return
	}
	y2, ok := findY2(px, py)
	if ok {
		return
	}
	check((x1+x2)/2, (y1+y2)/2) // Should return CENTER
}

func findY1(px, py int) (int, bool) {
	hi := py
	lo := -BOUND
	for lo < hi {
		mid := (hi+lo+BOUND*2)/2 - BOUND
		s := check(px, mid)
		if s == "CENTER" {
			return mid, true
		}
		if s == "HIT" {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	return lo, false
}

func findY2(px, py int) (int, bool) {
	lo := py
	hi := BOUND
	for lo < hi {
		mid := (hi+lo+BOUND*2)/2 - BOUND + 1
		s := check(px, mid)
		if s == "CENTER" {
			return mid, true
		}
		if s == "HIT" {
			lo = mid
		} else {
			hi = mid - 1
		}
	}
	return lo, false
}

func findX1(px, py int) (int, bool) {
	hi := px
	lo := -BOUND
	for lo < hi {
		mid := (hi+lo+BOUND*2)/2 - BOUND
		s := check(mid, py)
		if s == "CENTER" {
			return mid, true
		}
		if s == "HIT" {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	return lo, false
}

func findX2(px, py int) (int, bool) {
	lo := px
	hi := BOUND
	for lo < hi {
		mid := (hi+lo+BOUND*2)/2 - BOUND + 1
		s := check(mid, py)
		if s == "CENTER" {
			return mid, true
		}
		if s == "HIT" {
			lo = mid
		} else {
			hi = mid - 1
		}
	}
	return lo, false
}

func check(x, y int) (s string) {
	fmt.Println(x, y)
	fmt.Scanf("%s\n", &s)
	return
}
