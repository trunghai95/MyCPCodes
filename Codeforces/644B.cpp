#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define F first
#define S second

int n, b;
pii a[200010];
queue<int> q;
ll res[200010];

int main()
{
	scanf("%d %d", &n, &b);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].F, &a[i].S);

	int i = 0;
	ll t = 0;
	memset(res, -1, sizeof(res));

	while (i < n)
	{
		res[i] = t = a[i].F + a[i].S;
		++i;

		while (i < n && a[i].F < t)
		{
			if (q.size() < b)
				q.push(i);
			++i;
		}

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			res[u] = t = t + a[u].S;
			while (i < n && a[i].F < t)
			{
				if (q.size() < b)
					q.push(i);
				++i;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		printf("%lld ", res[i]);
	return 0;
}