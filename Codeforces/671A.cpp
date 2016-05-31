#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld,ld> pld;
#define x first
#define y second

const ld EPS = 0.0000000001;

int n, ax, ay, bx, by, tx, ty, x, y;
pld a, b, t, p[100010];
bool ck[100010];

ld dist(pld a, pld b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
	scanf("%d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty, &n);
	a.x = ax, a.y = ay;
	b.x = bx, b.y = by;
	t.x = tx, t.y = ty;

	ld sum = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y), p[i].x = x, p[i].y = y;
		sum += dist(p[i], t)*2;
	}

	ld res = 0;
	if (n == 1)
		res = min(dist(p[0], a) + dist(p[0], t), dist(p[0], b) + dist(p[0], t));
	else
	{
		ld sumtmp = sum, res1 = sum, tmp;
		int tmpi = 0;
		res1 = sumtmp - dist(p[0], t) + dist(p[0], a);
		for (int i = 0; i < n; ++i)
		{
			if ((tmp = sumtmp - dist(p[i], t) + dist(p[i], a)) < res1)
				res1 = tmp, tmpi = i;
		}
		sumtmp = res1;
		for (int i = 0; i < n; ++i)
		if (i != tmpi)
		{
			if ((tmp = sumtmp - dist(p[i], t) + dist(p[i], b)) < res1)
				res1 = tmp;
		}

		res = res1;

		sumtmp = sum; res1 = sum;
		tmpi = 0;
		res1 = sumtmp - dist(p[0], t) + dist(p[0], b);
		for (int i = 0; i < n; ++i)
		{
			if ((tmp = sumtmp - dist(p[i], t) + dist(p[i], b)) < res1)
				res1 = tmp, tmpi = i;
		}
		sumtmp = res1;
		for (int i = 0; i < n; ++i)
		if (i != tmpi)
		{
			if ((tmp = sumtmp - dist(p[i], t) + dist(p[i], a)) < res1)
				res1 = tmp;
		}

		res = min(res, res1);
	}

	cout << setprecision(15) << res;
	return 0;
}