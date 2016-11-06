def gcd(x, y):
    xx = x
    yy = y
    while xx > 0:
        r = yy % xx;
        yy = xx
        xx = r
    return yy

n = input()
a = map(int, raw_input().split())
a.sort()
g = a[1] - a[0]
for i in range(2, n):
    g = gcd(g, a[i] - a[i-1])
if a[0] % g == 0:
    res = 0
else:
    res = g - (a[0] % g)
print res