#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[100010], res, sum;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", a+i);
		sum += a[i];
	}

	for (int i = 1; i <= n; ++i)
		res = max(res, a[i] - (sum - a[i]) + 1);

	if (res < 1)
		res = 1;

	printf("%lld", res);
	return 0;
}