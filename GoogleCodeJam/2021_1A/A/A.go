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

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var n int
	fmt.Fscan(in, &n)
	var s1, s2 string
	var res int64
	fmt.Fscan(in, &s1)
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &s2)
		if len(s1) < len(s2) {
			s1 = s2
			continue
		}

		flag := 0 // 0: equal, 1: s1 > s2, 2: s1 < s2
		for j := 0; j < len(s2); j++ {
			if s1[j] > s2[j] {
				flag = 1
				break
			} else if s1[j] < s2[j] {
				flag = 2
				break
			}
		}

		if flag == 0 {
			// fmt.Println(0)
			ok := false
			for j := len(s1) - 1; j >= len(s2); j-- {
				if s1[j] != '9' {
					for len(s2) < j {
						s2 = s2 + string(s1[len(s2)])
						res++
					}
					s2 = s2 + string(s1[j]+1)
					res++
					for len(s2) < len(s1) {
						s2 = s2 + string('0')
						res++
					}
					ok = true
					break
				}
			}
			if !ok {
				for len(s2) <= len(s1) {
					s2 = s2 + string('0')
					res++
				}
			}
		} else if flag == 1 {
			// fmt.Println(1)
			for len(s2) <= len(s1) {
				s2 = s2 + string('0')
				res++
			}
		} else {
			// fmt.Println(2)
			for len(s2) < len(s1) {
				s2 = s2 + string('0')
				res++
			}
		}

		s1 = s2
	}
	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}
