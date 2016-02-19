#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, nn;

int main()
{
	cin >> n;
	ll res = (n - 3)*9;
	ll tmp = 1;
	for (int i = 3; i < n; ++i)
		tmp *= 4;

	res *= tmp;
	tmp *= 4;
	res += tmp*6;
	printf("%lld", res);
	return 0;
}