#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll m[3][3][3] = {{{1, -2, 2}, {2, -1, 2}, {2, -2, 3}},
		{{1, 2, 2}, {2, 1, 2}, {2, 2, 3}},
		{{-1, 2, 2}, {-2, 1, 2}, {-2, 2, 3}}};

bool solve(ll a, ll b, ll c) {
	if (a > n && b > n) {
		return false;
	}

	if (n % a == 0) {
		cout << b*(n/a) << ' ' << c*(n/a) << '\n';
		return true;
	}

	if (n % b == 0) {
		cout << a*(n/b) << ' ' << c*(n/b) << '\n';
		return true;
	}

	for (int i = 0; i < 3; ++i) {
		ll aa = a * m[i][0][0] + b * m[i][0][1] + c * m[i][0][2];
		ll bb = a * m[i][1][0] + b * m[i][1][1] + c * m[i][1][2];
		ll cc = a * m[i][2][0] + b * m[i][2][1] + c * m[i][2][2];

		if (solve(aa, bb, cc))
			return true;
	}

	return false;
}

int main()
{
	cin >> n;

	if (!solve(3, 4, 5))
		cout << -1 << '\n';
	return 0;
}