package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 0; i < test; i++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int64, 0)
	b := make([]int64, 0)
	suma := int64(0)
	sumb := int64(0)

	tmp := int64(1)
	for i := 0; i < n; i++ {
		a = append(a, tmp)
		fmt.Fprintf(out, "%d ", tmp)
		suma += tmp
		tmp <<= 1
		if tmp > 1000000000 {
			break
		}
	}

	tmp = 1000000000
	for i := len(a); i < n; i++ {
		b = append(b, tmp)
		fmt.Fprintf(out, "%d ", tmp)
		sumb += tmp
		tmp--
	}

	fmt.Fprintln(out)
	out.Flush()

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &tmp)
		b = append(b, tmp)
		sumb += tmp
	}

	half := (suma + sumb) / 2
	if suma >= half {
		print(half)
		return
	}

	sort.Slice(b, func(i, j int) bool { return b[i] > b[j] })
	for _, x := range b {
		if x <= half {
			half -= x
			fmt.Fprintf(out, "%d ", x)
		}
	}
	print(half)
}

func print(sum int64) {
	tmp := int64(1)
	for sum > 0 {
		if sum&1 > 0 {
			fmt.Fprintf(out, "%d ", tmp)
		}
		sum >>= 1
		tmp <<= 1
	}
	fmt.Fprintln(out)
	out.Flush()
}
