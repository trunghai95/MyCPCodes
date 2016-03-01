#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define p first
#define x second
#define F first
#define S second

int n, d, m;
pii a[200010];
set<pii> segs;
set<pii>::iterator it, it2;
ll res;

int main()
{
	scanf("%d %d %d", &d, &n, &m);

	for (int i = 0; i < m; ++i)
		scanf("%d %d", &a[i].x, &a[i].p);

	sort(a, a+m);

	segs.insert(pii(0, min(n, d)));

	// for (it = segs.begin(); it != segs.end(); ++it)
	// 		printf("[%d %d] ", (*it).F, (*it).S);
	// 	printf("\n");

	for (int i = 0; i < m; ++i)
	{
		it2 = it = segs.lower_bound(pii(a[i].x + 1, -1));
		pii p1, p2;
		if (it == segs.end())
			p1 = pii(d, d);
		else
			p1 = *it;

		--it2;
		p2 = *it2;

		if (p2.S - a[i].x >= n)
			continue;

		if (a[i].x > p2.S)
		{
			if (a[i].x + n < p1.F)
			{
				res += (ll)n * a[i].p;
				segs.insert(pii(a[i].x, a[i].x + n));
			}
			else
			{
				res += (ll)(p1.F - a[i].x) * a[i].p;
				if (it != segs.end())
					segs.erase(it);
				segs.insert(pii(a[i].x, p1.S));
			}
		}
		else
		{
			if (a[i].x + n < p1.F)
			{
				res += (ll)(a[i].x + n - p2.S) * a[i].p;
				segs.erase(it2);
				segs.insert(pii(p2.F, a[i].x + n));
			}
			else
			{
				res += (ll)(p1.F - p2.S) * a[i].p;
				if (it != segs.end())
					segs.erase(it);
				segs.erase(it2);
				segs.insert(pii(p2.F, p1.S));
			}
		}

		// for (it = segs.begin(); it != segs.end(); ++it)
		// 	printf("[%d %d] ", (*it).F, (*it).S);
		// printf("\n");
	}

	if (segs.size() != 1)
		res = -1;
	else if ((*segs.begin()).second != d)
			res = -1;

	printf("%lld", res);
	return 0;
}