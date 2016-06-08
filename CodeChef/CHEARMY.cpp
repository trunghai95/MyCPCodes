#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld", &n);
		ll m = 0, pw = 1;
		--n;
		while (n)
		{
			m += (n%5) * pw;
			n /= 5;
			pw *= 10;
		}
		printf("%lld\n", m*2);
	}
	return 0;
}