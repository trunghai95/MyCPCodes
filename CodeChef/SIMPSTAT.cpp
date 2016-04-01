#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, k, a[10010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);
		sort(a, a+n);
		ll sum = 0;
		for (int i = k; i < n - k; ++i)
			sum += a[i];
		printf("%.9lf\n", (double)sum / (n - k*2));
	}
	return 0;
}