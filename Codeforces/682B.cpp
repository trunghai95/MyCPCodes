#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	sort(a+1, a+1+n);

	int res = 1, i = 1;

	while (i <= n)
	{
		if (res <= a[i])
			++res;
		++i;
	}

	printf("%d", res);
	return 0;
}