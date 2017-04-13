n, c1, c2 = map(int, raw_input().split(" "))
s = raw_input()
m = 0

for c in s:
    m += (c == '1')

res = 2e18
for i in range(1, m+1):
    a = n // i
    cnt = i - (n % i)
    tmp = cnt * (c1 + c2 * (a - 1) * (a - 1))
    a += 1
    cnt = n % i
    tmp += cnt * (c1 + c2 * (a - 1) * (a - 1))
    res = min(res, tmp)

print res
