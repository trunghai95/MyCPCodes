#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct Info
{
	pii lr;
	int id;
};

bool cmp(Info x, Info y)
{
	if (x.lr == y.lr)
		return x.id < y.id;
	return x.lr > y.lr;
}

#define L first
#define R second

int test, n;
Info a[111];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i].lr.L);
			a[i].id = i;
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i].lr.R);
			a[i].lr.L *= a[i].lr.R;
		}

		sort(a+1, a+1+n, cmp);
		printf("%d\n", a[1].id);
	}
	return 0;
}