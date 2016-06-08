#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int n, q, t, mx, mn;

int main()
{
	scanf("%d %d", &n, &q);
	mx = -INF;
	mn = INF;

	for (int i = 0, x; i < n; ++i)
	{
		scanf("%d", &x);
		mx = max(mx, x);
		mn = min(mn, x);
	}

	for (int i = 0, x; i < q; ++i)
	{
		scanf("%d", &x);
		if (x >= mn && x <= mx)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}