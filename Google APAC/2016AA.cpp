#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, n;
int res;
int test;

int main()
{
	scanf("%d", &test);

	for (int ii = 1; ii <= test; ++ii)
	{
		res = 0;
		scanf("%lld", &k);

		n = 1;
		while (n < k)
			n = n*2 + 1;

		while (k != n/2 + 1)
		{
			// cout << k << ' ' << n << ' ' << res << '\n';
			if (k > n/2)
				k = n - k + 1, res = 1 - res;
			n /= 2;
		}

		printf("Case #%d: %d\n", ii, res);
	}
	return 0;
}