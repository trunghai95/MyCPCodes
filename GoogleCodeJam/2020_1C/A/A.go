package main

import "fmt"

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func solve(t int) {
	var x, y int
	var s string
	fmt.Scanf("%d %d %s\n", &x, &y, &s)
	fmt.Printf("Case #%d: ", t)
	if x == 0 && y == 0 {
		fmt.Printf("0\n")
		return
	}

	for i, c := range s {
		switch c {
		case 'S':
			y -= 1
		case 'N':
			y += 1
		case 'E':
			x += 1
		case 'W':
			x -= 1
		}
		l := i + 1
		tmp := l - (abs(x) + abs(y))
		// fmt.Printf("%d %d %d %d\n", x, y, l, tmp)
		if tmp >= 0 {
			fmt.Printf("%d\n", l)
			return
		}
	}

	fmt.Printf("IMPOSSIBLE\n")
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
