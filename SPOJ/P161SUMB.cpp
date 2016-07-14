#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, t;

int main()
{
	scanf("%d %d", &n, &m);

	scanf("%d", &a);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t);
	scanf("%d", &b);
	for (int i = 0; i < m; ++i)
		scanf("%d", &t);

	t = __gcd(abs(a), abs(b));
	a /= t;
	b /= t;

	if (m > n)
		printf("0/1");
	else if (n > m)
	{
		if (a*b < 0)
			printf("-Infinity");
		else
			printf("Infinity");
	}
	else
	{
		if (b < 0)
			a = -a, b = -b;
		printf("%d/%d", a, b);
	}
	return 0;
}