n, m = map(int, input().split())
a = [0,]*(m+1)
tot = 0

for _ in range(n):
    i, x = map(int, input().split())
    a[i] += x
    tot += x

e = tot // m

print("1", a[1] - e - (tot - e*m))

for i in range(2, m+1):
    print(i, a[i] - e)
