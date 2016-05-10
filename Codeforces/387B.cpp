#include <bits/stdc++.h>

using namespace std;

int n, m, a[3010], b[3010];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for (int i = 1; i <= m; ++i)
		scanf("%d", b+i);

	int in = 1;

	for (int im = 1; im <= m && in <= n; ++im)
	if (b[im] >= a[in])
		++in;

	printf("%d", n - in + 1);

	return 0;
}