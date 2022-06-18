package main

import "fmt"

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

type ss struct {
	i    int
	jump bool
}

type pnt struct {
	x int
	y int
}

var res, n int
var mp map[int]bool
var p []pnt
var arr []ss

func solve(t int) {
	fmt.Scanf("%d", &n)
	p = make([]pnt, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &p[i].x, &p[i].y)
	}
	res = 0
	mp = make(map[int]bool)
	arr = make([]ss, 0)
	for i := 0; i < n; i++ {
		try(i, false)
	}
	fmt.Printf("Case #%d: %d\n", t, res)
}

func try(i int, jump bool) {
	arr = append(arr, ss{i, jump})
	mp[i] = true
	l := len(arr) - 1
	defer func() {
		mp[i] = false
		arr = arr[:len(arr)-1]
	}()

	if !jump {
		for j := l - 1; j > 0; j-- {
			if !arr[j].jump {
				// fmt.Println(arr, !parallel(vector(p[arr[l].i], p[arr[l-1].i]), vector(p[arr[j].i], p[arr[j-1].i])))
				if !parallel(vector(p[arr[l].i], p[arr[l-1].i]), vector(p[arr[j].i], p[arr[j-1].i])) {
					return
				}
				break
			}
		}
	}
	// fmt.Println(arr)
	res = max(res, len(arr))
	for j := 0; j < n; j++ {
		if !mp[j] {
			if jump {
				try(j, false)
			} else {
				try(j, true)
				try(j, false)
			}
		}
	}
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func vector(p1, p2 pnt) pnt {
	return pnt{p2.x - p1.x, p2.y - p1.y}
}

func parallel(v1, v2 pnt) bool {
	u1 := unit(v1)
	u2 := unit(v2)
	return u1.x == u2.x && u1.y == u2.y
}

func unit(v pnt) pnt {
	if v.x == 0 {
		return pnt{0, v.y / abs(v.y)}
	} else if v.y == 0 {
		return pnt{v.x / abs(v.x), 0}
	}
	g := gcd(abs(v.x), abs(v.y))
	return pnt{v.x / g, v.y / g}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
