package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var (
	in   = bufio.NewReader(os.Stdin)
	out  = bufio.NewWriter(os.Stdout)
	n    int
	arr1 [][]int
	arr2 [][]int
)

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 1; i <= test; i++ {
		fmt.Fprintf(out, "Case #%d: %d\n", i, solve())
	}
}

func solve() int {
	fmt.Fscan(in, &n)

	arr1 = make([][]int, n*2+1)
	arr2 = make([][]int, n*2+1)
	for i := 0; i <= n*2; i++ {
		arr1[i] = make([]int, n*2+1)
		arr2[i] = make([]int, n*2+1)
	}

	draw1()
	draw2()

	// for i := range arr1 {
	// 	for j := range arr1[i] {
	// 		fmt.Fprintf(out, "%d", arr1[i][j])
	// 	}
	// 	fmt.Fprintln(out)
	// }

	fmt.Fprintln(out)

	for i := range arr1 {
		for j := range arr1[i] {
			fmt.Fprintf(out, "%d", arr2[i][j])
		}
		fmt.Fprintln(out)
	}

	res := 0
	for i := range arr1 {
		for j := range arr1[i] {
			if arr1[i][j] != arr2[i][j] {
				res++
			}
		}
	}
	return res
}

func draw1() {
	for x := -n; x <= n; x++ {
		for y := -n; y <= n; y++ {
			if math.Round(math.Sqrt(float64(x*x+y*y))) <= float64(n) {
				fillPixel1(x, y)
			}
		}
	}
}

func drawCircle(r int) {
	// fmt.Fprintln(out, "drawCircle", r)
	for x := -r; x <= r; x++ {
		y := int(math.Round(math.Sqrt(float64(r*r - x*x))))
		// fmt.Fprintln(out, x, y)
		fillPixel2(x, y)
		fillPixel2(x, -y)
		fillPixel2(y, x)
		fillPixel2(-y, x)
	}
}

func draw2() {
	for r := 0; r <= n; r++ {
		drawCircle(r)
	}
}

func fillPixel1(x, y int) {
	arr1[x+n][y+n] = 1
}

func fillPixel2(x, y int) {
	arr2[x+n][y+n] = 1
}
