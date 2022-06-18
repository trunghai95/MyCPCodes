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

	var t, n, x int
	fmt.Fscan(in, &t, &n)

	for t > 0 {
		t--
		for i := 1; i < n; i++ {
			fmt.Fprintf(out, "M %d %d\n", i, n)
			out.Flush()
			fmt.Fscan(in, &x)
			if x != i {
				fmt.Fprintf(out, "S %d %d\n", i, x)
				out.Flush()
				fmt.Fscan(in, &x)
			}
		}

		fmt.Fprintf(out, "D\n")
		out.Flush()
		fmt.Fscan(in, &x)
	}
}
