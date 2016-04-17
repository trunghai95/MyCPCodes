#include <bits/stdc++.h>

using namespace std;

int n, f[100010], x;
vector<int> pd[100010];
bool notPr[100010];

void init()
{
	for (int i = 2; i <= 100000; ++i)
	if (!notPr[i])
	{
		pd[i].push_back(i);
		for (int j = i*2; j <= 100000; j += i)
			notPr[j] = true, pd[j].push_back(i);
	}
}

int main()
{
	init();

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		int mx = 0;
		for (int j = 0; j < pd[x].size(); ++j)
			mx = max(mx, f[pd[x][j]]);
		++mx;

		for (int j = 0; j < pd[x].size(); ++j)
			f[pd[x][j]] = mx;
	}

	int res = 0;
	for (int i = 2; i <= 100000; ++i)
		res = max(res, f[i]);

	if (res == 0)
		res = 1;
	
	printf("%d", res);
	return 0;
}