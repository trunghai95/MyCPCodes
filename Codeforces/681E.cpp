#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> pdb;
typedef long long ll;

const double pi = acos(-1);
const double eps = 0.000000001;

double dist(double x, double y) { return x*x + y*y; }

double xx, yy, v, t, x, y, r;
int n;
vector<pdb> vt;

int main()
{
	scanf("%lf %lf %lf %lf %d", &xx, &yy, &v, &t, &n);
	if (t == 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf %lf", &x, &y, &r);
			if (dist(x-xx, y-yy) <= r*r)
			{
				printf("1.00000");
				return 0;
			}
		}
		printf("0.00");
		return 0;
	}

	v *= t;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf %lf", &x, &y, &r);
		x -= xx;
		y -= yy;
		double dd = dist(x, y);
		double d = sqrt(dd);
		if (dd < r*r + eps)
		{
			printf("1.0000");
			return 0;
		}

		if (d - eps > v + r)
			continue;

		double ang, ang1, ang2;
		
		ang = atan2(y, x);
		if (ang < 0)
			ang += pi*2;

		if (dd - r*r < v*v + eps)
			// tiep tuyen
			ang1 = asin(r / d);
		else
		{
			// cat nhau
			double tmp = 0.5 * (v*v - r*r + dd) / (d*v);
			ang1 = acos(tmp);
		}

		ang2 = ang + ang1;
		ang1 = ang - ang1;
		if (ang1 < 0)
		{
			vt.push_back(pdb(ang1 + pi*2, 1));
			vt.push_back(pdb(pi*2, -1));
			vt.push_back(pdb(0.0, 1));
			vt.push_back(pdb(ang2, -1));
		}
		else if (ang2 > pi*2)
		{
			vt.push_back(pdb(ang1, 1));
			vt.push_back(pdb(pi*2, -1));
			vt.push_back(pdb(0.0, 1));
			vt.push_back(pdb(ang2 - pi*2, -1));
		}
		else
		{
			vt.push_back(pdb(ang1, 1));
			vt.push_back(pdb(ang2, -1));
		}
	}

	double tot = 0, beg = 0;
	int cnt = 0;
	sort(vt.begin(), vt.end());

	for (int i = 0; i < (int)vt.size(); ++i)
	{
		if (cnt > 0)
			tot += vt[i].first - beg;
		cnt += vt[i].second;
		beg = vt[i].first;
	}

	tot /= pi*2;
	printf("%.12lf", tot);
	return 0;
}