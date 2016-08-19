#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	int res = 2e6;
	sort(a, a+n);

	for (int i = 0; i < n/2; ++i)
		res = min(res, a[i] + a[n-i-1]);

	printf("%d\n", res);
	return 0;
}