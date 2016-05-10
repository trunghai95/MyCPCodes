#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m, x, y;
pii a[100010], b[100010];
vector<pii> res;

int main()
{
	scanf("%d %d %d %d", &n, &m, &x, &y);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].first), a[i].second = i;
	for (int i = 1; i <= m; ++i)
		scanf("%d", &b[i].first), b[i].second = i;

	sort(a+1, a+1+n);
	sort(b+1, b+1+m);

	int i = 1, j = 1;

	while (j <= m)
	{
		while (i <= n && a[i].first + y < b[j].first)
			++i;
		// cout << i << ' ' << j << '\n';
		if (i > n)
			break;

		if (a[i].first - x <= b[j].first)
			res.push_back(pii(a[i].second, b[j].second)), ++i;
		++j;
	}

	printf("%d\n", res.size());
	for (i = 0; i < (int)res.size(); ++i)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}