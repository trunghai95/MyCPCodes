for tt in range(input()):
	x = input()
	lef = 0
	rig = 50002
	while lef < rig:
		mid = (lef + rig) / 2
		if 2**mid <= x:
			lef = mid + 1
		else:
			rig = mid
	print lef