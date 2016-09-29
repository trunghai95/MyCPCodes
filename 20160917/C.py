import sys
import math

tmp = 10**100 - 1

for inp in sys.stdin:
	if (inp == ''):
		continue
	x, p, q = map(int, inp.split())
	if (x == 1):
		print('NaN')
		continue

	tmp2 = int(math.floor(math.log(tmp, x)))

	if (p > tmp2 or q > tmp2):
		print('NaN')
		continue

	xp = x**p
	xq = x**q
	if ((xp - 1) % (xq - 1) != 0):
		print('NaN')
	else:
		print((xp - 1) // (xq - 1))