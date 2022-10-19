from sys import stdin

def solve(p, q):
    arr = []
    while p != q:
        if p > q:
            arr.append(True)
            p= p-q
        else:
            arr.append(False)
            q = q-p
    res = 0
    for x in reversed(arr):
        if x:
            res = (res + 1) * 2
        else:
            res = res * 2 + 1
    return res

for line in stdin:
    l = list(map(int, line.split(' ')))
    print(solve(l[0], l[1]))