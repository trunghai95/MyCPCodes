test = input()

def solve(x, y, p, q):
    if x*q == y*p:
        print 0
        return
    elif x*q > y*p:
        x = y - x
        p = q - p

    if p == 0 or p == q:
        print -1
        return

    lo = 1
    hi = 10**18

    while lo < hi:
        mid = (lo + hi) // 2
        if (x+mid)*q >= (y+mid)*p:
            hi = mid
        else:
            lo = mid + 1

    t = ((y + lo - 1) // q + 1) * q
    print t - y

while test > 0:
    x, y, p, q = map(int, raw_input().split())
    solve(x, y, p, q)
    test -= 1
