package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

type Node struct {
	val int64
	id  int
}

type Heap []Node

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(x, y int) bool { return h[x].val < h[y].val }
func (h Heap) Swap(x, y int)      { h[x], h[y] = h[y], h[x] }

func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(Node))
}

func (h *Heap) Pop() interface{} {
	old := *h
	ret := old[len(old)-1]
	*h = old[:len(old)-1]
	return ret
}

func main() {
	defer out.Flush()

	var test int
	fmt.Fscan(in, &test)
	for i := 1; i <= test; i++ {
		fmt.Fprintf(out, "Case #%d: %d\n", i, solve())
	}
}

func solve() int64 {
	var n, tmp int
	fmt.Fscan(in, &n)
	f := make([]int64, n)
	p := make([]int, n)
	mark := make([]bool, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &f[i])
		mark[i] = true
	}

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &tmp)
		tmp--
		p[i] = tmp
		if tmp >= 0 {
			mark[tmp] = false
		}
	}

	h := &Heap{}
	for i := 0; i < n; i++ {
		if mark[i] {
			heap.Push(h, Node{val: f[i], id: i})
		}
	}

	res := int64(0)
	for len(*h) > 0 {
		node := heap.Pop(h).(Node)
		// fmt.Println(node)

		if p[node.id] < 0 || mark[p[node.id]] {
			res += node.val
			// fmt.Println("---", res)
			continue
		}

		if f[p[node.id]] > node.val {
			node.val = f[p[node.id]]
		}
		node.id = p[node.id]
		mark[node.id] = true
		// fmt.Println("--", node)
		heap.Push(h, node)
	}

	return res
}
