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

	var n, k int
	fmt.Fscan(in, &n, &k)
	res := make([]int64, n)
	type Mod struct {
		t string
		l int
		r int
	}

	mod := make([][]Mod, n)

	for i := 0; i < k; i++ {
		var s string
		var l, r int
		fmt.Fscan(in, &s, &l, &r)
		l--
		r--
		if s == "R" || s == "D" || l == r {
			if s == "H" {
				s = "R"
			}
			if s == "V" {
				s = "D"
			}
			mod[l] = append(mod[l], Mod{s, l, r})
			if l != r {
				mod[r] = append(mod[r], Mod{s, l, r})
			}
		} else {
			m := (l + r) / 2
			mod[l] = append(mod[l], Mod{s + "1", l, m})
			if l != m {
				mod[m] = append(mod[m], Mod{s + "1", l, m})
			}
			mod[r] = append(mod[r], Mod{s + "2", m + 1, r})
			if r != m+1 {
				mod[m+1] = append(mod[m+1], Mod{s + "2", m + 1, r})
			}
		}
	}

	var cntD, cntR, cntH, cntV, curH, curV int64
	for i := 0; i < n; i++ {
		for _, m := range mod[i] {
			if m.l != i {
				continue
			}
			if m.t == "R" {
				cntR++
			} else if m.t == "D" {
				cntD++
			} else if m.t == "H1" {
				cntH++
			} else if m.t == "V1" {
				cntV++
			}
		}
		curH += cntH
		curV += cntV
		res[i] += cntR - cntD + curH - curV
		for _, m := range mod[i] {
			if m.r != i {
				continue
			}
			if m.t == "R" {
				cntR--
			} else if m.t == "D" {
				cntD--
			} else if m.t == "H1" {
				cntH--
				curH -= int64(m.r - m.l + 1)
			} else if m.t == "V1" {
				cntV--
				curV -= int64(m.r - m.l + 1)
			}
		}
	}
	cntH, cntV, curH, curV = 0, 0, 0, 0
	for i := n - 1; i >= 0; i-- {
		for _, m := range mod[i] {
			if m.r != i {
				continue
			}
			if m.t == "H2" {
				cntH++
			} else if m.t == "V2" {
				cntV++
			}
		}
		curH += cntH
		curV += cntV
		res[i] += cntR - cntD + curH - curV
		for _, m := range mod[i] {
			if m.l != i {
				continue
			}
			if m.t == "H2" {
				cntH--
				curH -= int64(m.r - m.l + 1)
			} else if m.t == "V2" {
				cntV--
				curV -= int64(m.r - m.l + 1)
			}
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d\n", res[i])
	}
}
