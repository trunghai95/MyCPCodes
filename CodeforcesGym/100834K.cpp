#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;

double PI = acos(-1.0);
const double EPS = 1e-7;
int X, Y, h, r, n, x, y, z;
int bot1, bot2;
vector<pdd> v;

int main()
{
	scanf("%d %d %d %d %d", &X, &Y, &h, &r, &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);

		x -= X, y -= Y;

		if (z < 0)
			bot1 = 1;
		if (z > h)
			bot2 = 1;

		if (x*x + y*y <= r*r)
			continue;

		double dist = sqrt(1.0*x*x + y*y);

		double ang = atan(1.0*y/x);
		if (x < 0)
			ang += PI;

		if (ang > PI*2)
			ang -= PI*2;
		else if (ang < 0)
			ang += PI*2;

		// cout << ang << "abc\n";

		double tmp = acos(1.0*r/dist);
		double ang1 = ang - tmp;
		double ang2 = ang + tmp;
		if (ang2 + EPS > PI*2)
			ang1 -= PI*2, ang2 -= PI*2;
		if (ang2 < EPS)
			ang1 += PI*2, ang2 += PI*2;

		if (ang1 < EPS)
			v.push_back(pdd(ang1 + PI*2, PI*2)), v.push_back(pdd(0, ang2));
		else
			v.push_back(pdd(ang1, ang2));
	}

	sort(v.begin(), v.end());

	double res = 0;

	double lef = 0, rig = 0;

	for (int i = 0; i < (int)v.size(); ++i)
	{
		// cout << v[i].first << ' ' << v[i].second << ' ' << lef << ' ' << rig << '\n';
		if (v[i].first + EPS > rig)
		{
			res += rig - lef;
			lef = v[i].first;
			rig = v[i].second;
		}
		else
			rig = max(rig, v[i].second);
	}

	res += rig - lef;

	res = res*r*h + PI*r*r*(bot1+bot2);

	printf("%.12lf\n", res);
	return 0;
}