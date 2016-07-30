#include <bits/stdc++.h>

using namespace std;

int n, k, a[100], mn, res;

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	mn = max(1, a[k]);

	for (int i = 1; i <= n; ++i)
		res += (a[i] >= mn);

	printf("%d\n", res);
	return 0;
}