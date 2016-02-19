import math
a, b, c = map(float, raw_input().split())
goc = 36.0/180.0*math.pi
print a**3/math.sqrt(2)/6.0 + b**3/math.sqrt(2)/3.0 + c**3*math.sqrt(math.sin(goc)**2*4-1)/math.sin(goc)/math.tan(goc)*5/24