#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k, a, b;

int main()
{
	scanf("%lld", &n);

	if (n <= 2) {
		printf("-1\n");
		return 0;
	}

	if (n&1) {
		a = n*n;
		b = 1;
	} else {
		a = n*n / 2;
		b = 2;
	}

	m = (a - b) / 2;
	k = (a + b) / 2;

	printf("%lld %lld\n", m, k);
	return 0;
}