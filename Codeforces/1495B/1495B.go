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

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	if n == 2 {
		fmt.Fprintln(out, 0)
		return
	}

	inc := (a[0] < a[1])
	cur := 2
	maxLen := 0
	maxCnt := 0
	flag := false
	ff := false

	for i := 2; i < n; i++ {
		if inc == (a[i] < a[i-1]) {
			inc = !inc
			if cur > maxLen {
				maxLen = cur
				maxCnt = 1
				ff = true
				flag = false
			} else if cur == maxLen {
				if ff && !inc {
					flag = true
				}
				maxCnt++
			} else {
				ff = false
			}
			cur = 2
		} else {
			cur++
		}

		// fmt.Fprintln(out, i, inc, cur, maxLen, maxCnt, ff, flag)
	}

	if cur > maxLen {
		maxLen = cur
		maxCnt = 1
		flag = false
	} else if cur == maxLen {
		if ff && !inc {
			flag = true
		}
		maxCnt++
	}

	// fmt.Fprintln(out, maxCnt, maxLen, flag)

	if maxLen%2 == 0 {
		fmt.Fprintln(out, 0)
	} else if maxCnt == 1 || (maxCnt == 2 && flag) {
		fmt.Fprintln(out, 1)
	} else {
		fmt.Fprintln(out, 0)
	}
}
