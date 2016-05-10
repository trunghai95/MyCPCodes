#include <bits/stdc++.h>

using namespace std;

int n, k, a[100010];

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	int cur = 1;

	while (k > cur)
	{
		k -= cur;
		++cur;
	}

	printf("%d", a[k]);
	return 0;
}