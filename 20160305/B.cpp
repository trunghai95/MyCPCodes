#include <bits/stdc++.h>

using namespace std;

int test, n, x, p[100010], bit[100010];

void update(int x)
{
	while (x <= 100000)
	{
		++bit[x];
		x += x&(-x);
	}
}

int get(int x)
{
	int res = 0;
	while (x)
	{
		res += bit[x];
		x -= x&(-x);
	}
	return res;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		vector<int> v;
		memset(bit, 0, sizeof(bit));

		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", p+i);
		}

		for (int i = n; i >= 1; --i)
		{
			if (get(p[i]) > 0)
				v.push_back(p[i]);
			update(p[i]);
		}

		sort(v.begin(), v.end());

		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); ++i)
			printf("%d\n", v[i]);
	}
	return 0;
}