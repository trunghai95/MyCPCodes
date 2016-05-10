#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 0.00000001;

ld X1, X2, Y1, Y2, vx1, vx2, vy1, vy2;

ld distSqr(ld t)
{
	ld t1 = X1 - X2 + t*(vx1 - vx2);
	ld t2 = Y1 - Y2 + t*(vy1 - vy2);
	return t1*t1 + t2*t2;
}

ld dist(ld t)
{
	return sqrt(distSqr(t));
}

int main()
{
	cin >> X1 >> Y1 >> X2 >> Y2 >> vx1 >> vy1 >> vx2 >> vy2;

	ld lef = 0, rig = 1e30;

	while (rig - lef > EPS)
	{
		// printf("%lf - %lf\n", lef, rig);
		ld p1 = lef + (rig - lef) / 3.0;
		ld p2 = rig - (rig - lef) / 3.0;
		if (distSqr(p1) > distSqr(p2))
			lef = p1;
		else
			rig = p2;
	}

	cout << setprecision(15) << fixed << dist(lef);

	return 0;
}