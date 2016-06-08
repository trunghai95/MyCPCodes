#include <bits/stdc++.h>

using namespace std;

int n, sum, mn[40], mx[40];

int main()
{
	scanf("%d %d", &n, &sum);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", mn+i, mx+i);
		sum -= mn[i];
	}

	if (sum < 0)
	{
		printf("NO");
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		if (mn[i] + sum <= mx[i])
		{
			mn[i] += sum, sum = 0;
			break;
		}
		sum -= mx[i] - mn[i];
		mn[i] = mx[i];
	}

	if (sum)
		printf("NO");
	else
	{
		printf("YES\n");
		for (int i = 0; i < n; ++i)
			printf("%d ", mn[i]);
	}
	return 0;
}