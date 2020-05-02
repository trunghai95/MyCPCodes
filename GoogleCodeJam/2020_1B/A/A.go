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
	var X, Y int
	fmt.Scanf("%d %d", &X, &Y)
	fmt.Printf("Case #%v: ", t)
	if (X+Y)&1 == 0 {
		fmt.Println("IMPOSSIBLE")
		return
	}
	for X != 0 || Y != 0 {
		if X == 0 {
			if Y == 1 {
				fmt.Print("N")
				break
			} else if Y == -1 {
				fmt.Print("S")
				break
			}
		} else if Y == 0 {
			if X == 1 {
				fmt.Print("E")
				break
			} else if X == -1 {
				fmt.Print("W")
				break
			}
		}
		if X&1 != 0 {
			Y /= 2
			if Y&1 == 0 {
				if ((X-1)/2)&1 != 0 {
					fmt.Print("E")
					X = (X - 1) / 2
				} else {
					fmt.Print("W")
					X = (X + 1) / 2
				}
			} else {
				if ((X-1)/2)&1 == 0 {
					fmt.Print("E")
					X = (X - 1) / 2
				} else {
					fmt.Print("W")
					X = (X + 1) / 2
				}
			}
		} else {
			X /= 2
			if X&1 == 0 {
				if ((Y-1)/2)&1 != 0 {
					fmt.Print("N")
					Y = (Y - 1) / 2
				} else {
					fmt.Print("S")
					Y = (Y + 1) / 2
				}
			} else {
				if ((Y-1)/2)&1 == 0 {
					fmt.Print("N")
					Y = (Y - 1) / 2
				} else {
					fmt.Print("S")
					Y = (Y + 1) / 2
				}
			}
		}
	}
	fmt.Println()
}
