package main

import (
	"fmt"
	"strings"
)

func main() {
	var test int
	fmt.Scanf("%d", &test)
	for i := 1; i <= test; i++ {
		solve(i)
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func reverse(s string) string {
	res := ""
	for i := 0; i < len(s); i++ {
		res = res + string(s[len(s)-i-1])
	}
	return res
}

func solvePre(pre []string) (string, bool) {
	id := 0
	res := ""
	for {
		found := false
		for _, s := range pre {
			if id < len(s) {
				if len(res) <= id {
					res = res + string(s[id])
				} else {
					if res[id] != s[id] {
						return "", false
					}
				}
				found = true
			}
		}
		id++
		if !found {
			break
		}
	}
	return res, true
}

func solveSuf(suf []string) (string, bool) {
	for i := range suf {
		suf[i] = reverse(suf[i])
	}
	res, ok := solvePre(suf)
	if ok {
		res = reverse(res)
	}
	return res, ok
}

func solve2(s []string) (string, bool) {
	n := len(s)
	pre := make([]string, n)
	suf := make([]string, n)
	mid := make([]string, n)
	for i := 0; i < n; i++ {
		id := strings.IndexByte(s[i], byte('*'))
		idLast := strings.LastIndexByte(s[i], byte('*'))
		// fmt.Println(s[i], id, idLast)
		pre[i] = s[i][0:id]
		suf[i] = s[i][idLast+1:]
		if id < idLast {
			mid[i] = s[i][id+1 : idLast]
		}
	}
	resp, okp := solvePre(pre)
	ress, oks := solveSuf(suf)
	if !okp || !oks {
		return "", false
	}
	resm := ""
	for _, s := range mid {
		for _, c := range s {
			if c != '*' {
				resm = resm + string(c)
			}
		}
	}
	return resp + resm + ress, true
}

func solve(t int) {
	var n int
	fmt.Scanf("%d", &n)
	s := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%s\n", &s[i])

	}
	fmt.Printf("Case #%v: ", t)
	res, ok := solve2(s)
	if ok {
		fmt.Printf("%s\n", res)
	} else {
		fmt.Printf("*\n")
	}
}
