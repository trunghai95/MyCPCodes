#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii, int> piii;

bool cmp(piii x, piii y)
{
	if (x.first.first == y.first.first)
		return x.first.second > y.first.second;
	return x.first.first > y.first.first;
}

int n, m, b[200010], c[200010], res;
map<int,int> cnt;
piii rr[200010];

int main()
{
	scanf("%d", &n);

	for (int i = 0, x; i < n; ++i)
	{
		scanf("%d", &x);
		++cnt[x];
	}

	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", b+i);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", c+i);
		rr[i] = piii(pii(cnt[b[i]], cnt[c[i]]), i);
	}

	sort(rr+1, rr+1+m, cmp);

	printf("%d", rr[1].second);
	return 0;
}