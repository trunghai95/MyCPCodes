#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll r, c, m, k, j;

bool Try(ll x, ll y, ll z)
{
	if (x % r == 0)
	{
		ll tmp = c - x / r;
		if (tmp > 0 && y % tmp == 0 && z % tmp == 0 && y/tmp + z/tmp == r)
			return true;
	}
	if (x % c == 0)
	{
		ll tmp = r - x / c;
		if (tmp > 0 && y % tmp == 0 && z % tmp == 0 && y/tmp + z/tmp == c)
			return true;
	}
	if (x % r == 0 && y % r == 0 && z % r == 0)
	{
		if (x/r + y/r + z/r == c)
			return true;
	}
	if (x % c == 0 && y % c == 0 && z % c == 0)
	{
		if (x/c + y/c + z/c == r)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld %lld %lld %lld %lld", &r, &c, &m, &k, &j);
		if (m + k + j != r*c)
		{
			printf("No\n");
			continue;
		}

		if (Try(m,k,j) || Try(k,m,j) || Try(j,m,k))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}