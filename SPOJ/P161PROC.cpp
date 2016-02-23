#include <bits/stdc++.h>

using namespace std;

int n, k, x;
vector<int> a;
int cnt[100010];

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	a.push_back(x);

	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &x);
		if (x != a.back())
			a.push_back(x);
	}

	for (int i = 1; i <= k; ++i)
		cnt[i] = a.size() - 1;

	for (int i = 1; i < (int)a.size() - 1; ++i)
		cnt[a[i]] -= (a[i-1] != a[i+1] ? 1 : 2);
	--cnt[a[0]];
	if (a.size() > 1) --cnt[a.back()];

	int mn = 1000000000, mnp = -1;

	for (int i = 1; i <= k; ++i)
	if (cnt[i] < mn)
		mn = cnt[i], mnp = i;

	printf("%d", mnp);
	return 0;
}