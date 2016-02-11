#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int test, k;
ll n, m;

ld f(ll nn, ll mm)
{
	return (ld)nn*(nn+1)*mm*(mm+1)/m/(m+1)/n/(n+1);
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld %lld %d", &n, &m, &k);
		ld res = 0;

		for (int i = 0; i < k; ++i)
		{
			ll p;
			scanf("%lld", &p);
			ll row = (p - 1) / m + 1;
			ll col = (p - 1) % m + 1;

			res -= f(n, col - 1) + f(n, m - col)+ f(m, row - 1) + f(m, n - row)
				- f(row - 1, col - 1) - f(row - 1, m - col)
				- f(n - row, col - 1) - f(n - row, m - col);
			res += (ld)1;
		}

		printf("%.16lf\n", (double)res);
	}
	return 0;
}