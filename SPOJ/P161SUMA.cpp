#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

ll solve(ll x, ll y)
{
	if (!x)
		return 0;
	return y/x + solve(y%x, x);
}

int main()
{
	cin >> a >> b;
	cout << solve(a,b);
	return 0;
}