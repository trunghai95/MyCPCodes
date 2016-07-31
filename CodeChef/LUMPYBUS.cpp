#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, a[100010];
ll p, q;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %lld %lld", &n, &p, &q);

		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);

		sort(a, a+n);

		for (int i = 0; i < n; ++i)
		{
			if (!p && (a[i] & 1))
				continue;
			// cout << a[i] << ' ' << p << ' ' << q << '\n';
			ll tmp = min(q, (ll)a[i] / 2);
			q -= tmp;
			a[i] -= tmp*2;

			tmp = min(p, (ll)a[i]);
			p -= tmp;
			a[i] -= tmp;

			// cout << a[i] << ' ' << p << ' ' << q << '\n';
		}

		int res = 0;
		for (int i = 0; i < n; ++i)
			res += (a[i] == 0);
		printf("%d\n", res);
	}
	return 0;
}