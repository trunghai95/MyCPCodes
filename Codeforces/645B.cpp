#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

int main()
{
	cin >> n >> k;
	ll res = 0;

	for (int i = 1; i <= min(n/2, k); ++i)
	{
		res += n*2 - i*4 + 1;
	}

	cout << res;

	return 0;
}