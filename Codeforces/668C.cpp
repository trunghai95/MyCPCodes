#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;

#define F first
#define S second

const ld EPS = 0.000001;

int n;
ld pmax[100010], pmin[100010], pa[100010], pb[100010], sumpa, sumpb;

pdd solve2dEq(ld a, ld b, ld c)
{
	pdd res;
	ld delta = b*b - a*c*4.0;
	if (delta < 0) delta = 0;
	// printf("%lf %lf %lf - %lf\n", a, b, c, delta);
	// cout << a << ' ' << b << ' ' << c << " - " << delta << '\n';
	delta = sqrt(delta);
	res.F = (-b + delta) / (a * (ld)2);
	res.S = (-b - delta) / (a * (ld)2);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	// scanf("%d", &n);
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> pmax[i];
		// scanf("%lf", pmax+i);
	for (int i = 1; i <= n; ++i)
		cin >> pmin[i];
		// scanf("%lf", pmin+i);

	for (int i = 1; i <= n; ++i)
	{
		ld A = pmax[i] + pmin[i];
		pdd tmp = solve2dEq(1.0, sumpb - sumpa - A, pmax[i] - A*sumpb);
		ld ta, tb;
		if (tmp.F < -EPS || A - tmp.F < -EPS)
			tb = tmp.S, ta = A - tmp.S;
		else if (tmp.S < -EPS || A - tmp.F < -EPS)
			tb = tmp.F, ta = A - tmp.F;
		else
		{
			tb = tmp.F, ta = A - tmp.F;
			if (tb < -EPS || tb > 1.0 - sumpb || ta < -EPS || ta > 1.0 - sumpa
				|| abs(ta*(1.0 - sumpb) + tb*(1.0 - sumpa) - ta*tb - pmin[i]) > EPS)
				tb = tmp.S, ta = A - tmp.S;
		}
		pa[i] = ta, pb[i] = tb;
		sumpa += ta, sumpb += tb;
		// printf("%.10lf %.10lf\n", sumpa, sumpb);
	}

	cout << setprecision(10);
	for (int i = 1; i <= n; ++i)
		cout << pa[i] << ' ';
		// printf("%.10lf ", pa[i]);
	// printf("\n");
	cout << '\n';
	for (int i = 1; i <= n; ++i)
		cout << pb[i] << ' ';
		// printf("%.10lf ", pb[i]);
	return 0;
}