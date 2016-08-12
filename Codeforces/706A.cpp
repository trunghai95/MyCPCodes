#include <bits/stdc++.h>

using namespace std;

int a, b, n, x, y, v;

int main()
{
	scanf("%d %d %d", &a, &b, &n);

	double res = 2e9;
	while (n--)
	{
		scanf("%d %d %d", &x, &y, &v);
		x -= a;
		y -= b;
		double tmp = 1.0*x*x + y*y;
		tmp = sqrt(tmp) / v;
		res = min(res, tmp);
	}

	printf("%.12lf\n", res);
	return 0;
}