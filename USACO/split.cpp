#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define F first
#define S second

int n;
pll pos[50010];
ll area, minSuf[50010], maxSuf[50010], minPre, maxPre;

bool cmps(pll x, pll y)
{
	if (x.S == y.S)
		return x.F < y.F;
	return x.S < y.S;
}

int main()
{
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	scanf("%d", &n);

	ll minF = 2e9, maxF = 0, minS = 2e9, maxS = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld %lld", &pos[i].F, &pos[i].S);
		minF = min(minF, pos[i].F);
		maxF = max(maxF, pos[i].F);
		minS = min(minS, pos[i].S);
		maxS = max(maxS, pos[i].S);
	}

	area = 2e18;

	sort(pos+1, pos+n+1);
	minSuf[n] = maxSuf[n] = pos[n].S;
	minPre = 2e9, maxPre = 0;
	for (int i = n-1; i > 0; --i)
	{
		minSuf[i] = min(minSuf[i+1], pos[i].S);
		maxSuf[i] = max(maxSuf[i+1], pos[i].S);
	}

	for (int i = 1; i < n; ++i)
	{
		minPre = min(minPre, pos[i].S);
		maxPre = max(maxPre, pos[i].S);
		area = min(area, (maxPre - minPre) * (pos[i].F - pos[1].F)
			+ (maxSuf[i+1] - minSuf[i+1]) * (pos[n].F - pos[i+1].F));
	}

	sort(pos+1, pos+n+1, cmps);
	minSuf[n] = maxSuf[n] = pos[n].F;
	minPre = 2e9, maxPre = 0;
	for (int i = n-1; i > 0; --i)
	{
		minSuf[i] = min(minSuf[i+1], pos[i].F);
		maxSuf[i] = max(maxSuf[i+1], pos[i].F);
	}

	for (int i = 1; i < n; ++i)
	{
		minPre = min(minPre, pos[i].F);
		maxPre = max(maxPre, pos[i].F);
		area = min(area, (maxPre - minPre) * (pos[i].S - pos[1].S)
			+ (maxSuf[i+1] - minSuf[i+1]) * (pos[n].S - pos[i+1].S));
	}

	printf("%lld", max((maxF - minF) * (maxS - minS) - area, 0LL));

	return 0;
}