#include <bits/stdc++.h>

using namespace std;

int n, a[100010], q, x;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		++a[x];
	}

	for (int i = 1; i <= 100000; ++i)
		a[i] += a[i-1];

	scanf("%d", &q);

	while (q--)
	{
		scanf("%d", &x);
		if (x > 100000)
			printf("%d\n", n);
		else
			printf("%d\n", a[x]);
	}
	return 0;
}