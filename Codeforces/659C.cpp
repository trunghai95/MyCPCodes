#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, a[100010];
vector<int> res;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	sort(a+1, a+1+n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = a[i-1] + 1; j < a[i]; ++j)
		{
			if (j <= m)
				res.push_back(j), m -= j;
			else
				break;
		}
		if (a[i] >= m)
			break;
	}

	int i = a[n] + 1;
	while (i <= m)
	{
		res.push_back(i);
		m -= i;
		++i;
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i)
		printf("%d ", res[i]);

	return 0;
}