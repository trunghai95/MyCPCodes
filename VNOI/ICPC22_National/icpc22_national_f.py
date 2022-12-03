test = int(input())
while test > 0:
    test -= 1
    s = input()
    f = input()
    l = input()
    if s == l + f:
        print("YES")
    else:
        print("NO")