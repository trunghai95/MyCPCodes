#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200000;
const int MAXLOG = 18;
const int INF = 2e9;

int n, a[MAXN], b[MAXN], ma[MAXN][MAXLOG], mb[MAXN][MAXLOG], pow2[MAXLOG];

void init()
{
	pow2[0] = 1;
	for (int i = 1; i < MAXLOG; ++i)
		pow2[i] = pow2[i-1] * 2;

	for (int i = n-1; i >= 0; --i)
	{
		ma[i][0] = a[i];
		for (int j = 1; j < MAXLOG; ++j)
		{
			if (i + pow2[j] > n)
				ma[i][j] = -INF;
			else
				ma[i][j] = max(ma[i][j - 1], ma[i + pow2[j - 1]][j - 1]);
		}
	}

	for (int i = n-1; i >= 0; --i)
	{
		mb[i][0] = b[i];
		for (int j = 1; j < MAXLOG; ++j)
		{
			if (i + pow2[j] > n)
				mb[i][j] = INF;
			else
				mb[i][j] = min(mb[i][j - 1], mb[i + pow2[j - 1]][j - 1]);
		}
	}
}

int rmqa(int p, int len)
{
	if (len == 0)
		return -INF;
	int i;
	for (i = MAXLOG - 1; pow2[i] > len; --i);
	return max(ma[p][i], rmqa(p + pow2[i], len - pow2[i]));
}

int rmqb(int p, int len)
{
	if (len == 0)
		return INF;
	int i;
	for (i = MAXLOG - 1; pow2[i] > len; --i);
	return min(mb[p][i], rmqb(p + pow2[i], len - pow2[i]));
}

int bs1(int p)
{
	int lef = p, rig = n-1;

	while (lef < rig)
	{
		int mid = (lef + rig) / 2;
		int tmp = rmqa(p, mid - p + 1) - rmqb(p, mid - p + 1);
		if (tmp < 0)
			lef = mid + 1;
		else
			rig = mid;
	}
	return lef;
}

int bs2(int p)
{
	int lef = p, rig = n-1;

	while (lef < rig)
	{
		int mid = (lef + rig) / 2 + 1;
		int tmp = rmqa(p, mid - p + 1) - rmqb(p, mid - p + 1);
		if (tmp > 0)
			rig = mid - 1;
		else
			lef = mid;
	}
	return lef;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	for (int i = 0; i < n; ++i)
		scanf("%d", b+i);

	init();

	ll res = 0;

	for (int i = 0; i < n; ++i)
	{
		int l = bs1(i);
		int r = bs2(i);

		if (rmqa(i, l - i + 1) == rmqb(i, l - i + 1))
			res += (r - l + 1);
	}

	printf("%lld", res);
	
	return 0;
}