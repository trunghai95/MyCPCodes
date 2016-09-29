n, k = map(int, raw_input().split())

tmp = 10**k
lo = 1 * tmp
hi = n * tmp
n = n * tmp * tmp

while (lo < hi):
	mid = (lo + hi) // 2 + 1
	if (mid*mid > n):
		hi = mid - 1
	else:
		lo = mid

r1 = lo // tmp
r2 = lo % tmp

print "%d.%0*d" % (r1, k, r2)