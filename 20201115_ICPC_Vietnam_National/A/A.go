package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in     = bufio.NewReader(os.Stdin)
	out    = bufio.NewWriter(os.Stdout)
	monMap = map[string]int{
		"Jan": 1,
		"Feb": 2,
		"Mar": 3,
		"Apr": 4,
		"May": 5,
		"Jun": 6,
		"Jul": 7,
		"Aug": 8,
		"Sep": 9,
		"Oct": 10,
		"Nov": 11,
		"Dec": 12,
	}
)

func main() {
	defer out.Flush()
	var t int
	fmt.Fscan(in, &t)
	for t > 0 {
		s := solve()
		fmt.Fprintf(out, "%s\n", s)
		t--
	}
}

func solve() string {
	var d int
	var s string
	fmt.Fscan(in, &d, &s)
	m := monMap[s]

	if isGte(d, m, 22, 12) {
		return "Capricorn"
	}
	if isGte(d, m, 23, 11) {
		return "Sagittarius"
	}
	if isGte(d, m, 23, 10) {
		return "Scorpio"
	}
	if isGte(d, m, 22, 9) {
		return "Libra"
	}
	if isGte(d, m, 23, 8) {
		return "Virgo"
	}
	if isGte(d, m, 23, 7) {
		return "Leo"
	}
	if isGte(d, m, 22, 6) {
		return "Cancer"
	}
	if isGte(d, m, 21, 5) {
		return "Gemini"
	}
	if isGte(d, m, 21, 4) {
		return "Taurus"
	}
	if isGte(d, m, 21, 3) {
		return "Aries"
	}
	if isGte(d, m, 20, 2) {
		return "Pisces"
	}
	if isGte(d, m, 21, 1) {
		return "Aquarius"
	}
	return "Capricorn"
}

func isGte(d1, m1, d2, m2 int) bool {
	if m1 > m2 {
		return true
	}
	if m1 == m2 {
		return d1 >= d2
	}
	return false
}
