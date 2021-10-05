package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)

	tpe = flag.Int("type", 1, "sub prob 1 or 2")
)

func main() {
	defer out.Flush()

	flag.Parse()

	var t int
	fmt.Fscan(in, &t)
	for i := 1; i <= t; i++ {
		solve(i)
	}
}

func solve(tt int) {
	var s string
	fmt.Fscan(in, &s)

	dist := make([][]int, 26)
	for i := 0; i < 26; i++ {
		dist[i] = make([]int, 26)
		for j := 0; j < 26; j++ {
			dist[i][j] = -1
		}
		dist[i][i] = 0
	}

	if *tpe == 2 {
		var n int
		fmt.Fscan(in, &n)
		var p string
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &p)
			dist[id(p[0])][id(p[1])] = 1
		}
	} else {
		for i := 0; i < 26; i++ {
			for j := i + 1; j < 26; j++ {
				if isVowel(i) != isVowel(j) {
					dist[i][j] = 1
					dist[j][i] = 1
				}
			}
		}
	}

	for p := 0; p < 26; p++ {
		for i := 0; i < 26; i++ {
			for j := 0; j < 26; j++ {
				for k := 0; k < 26; k++ {
					if dist[i][j] != -1 && dist[j][k] != -1 {
						dist[i][k] = min(dist[i][k], dist[i][j]+dist[j][k])
					}
				}
			}
		}
	}

	res := -1
	for i := 0; i < 26; i++ {
		sum := 0
		for ci := range s {
			d := dist[id(s[ci])][i]
			if d == -1 {
				sum = -1
				break
			}
			sum += d
		}

		res = min(res, sum)
	}

	fmt.Fprintf(out, "Case #%d: %d\n", tt, res)
}

func id(c byte) int {
	return int(c - 'A')
}

func isVowel(i int) bool {
	c := 'A' + byte(i)
	if c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' {
		return true
	}
	return false
}

func min(x, y int) int {
	if x == -1 {
		return y
	}
	if y == -1 || x < y {
		return x
	}
	return y
}
