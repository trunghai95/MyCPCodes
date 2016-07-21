#include <bits/stdc++.h>

using namespace std;

int n, a[10010], d, i, j, k, res;

int main()
{
	scanf("%d %d", &n, &d);

	for (i = 0; i < n; ++i)
		scanf("%d", a+i);

	i = j = k = 0;

	while (i < n)
	{
		while (j < n && a[j] - a[i] < d)
			++j;
		while (k < n && a[k] - a[j] < d)
			++k;

		if (j == n || k == n)
			break;
		if (a[j] - a[i] == d && a[k] - a[j] == d)
			++res;
		++i;
	}

	printf("%d", res);
	return 0;
}