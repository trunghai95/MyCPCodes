#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m, k, type, tt, co;
pii colorR[5001], colorC[5001];

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d %d", &type, &tt, &co);
		if (type == 1)
			colorR[tt] = pii(co, i);
		else
			colorC[tt] = pii(co, i);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (colorR[i].second > colorC[j].second)
				printf("%d ", colorR[i].first);
			else
				printf("%d ", colorC[j].first);
		}

		printf("\n");
	}
	return 0;
}