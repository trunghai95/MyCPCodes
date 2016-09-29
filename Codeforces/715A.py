n = input()
cur = 2
for i in range(2, n+2):
	x = i*i*(i-1) - cur//(i-1)
	cur = i*(i-1)
	print(x)