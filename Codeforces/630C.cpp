#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int main()
{
	cin >> n;

	ll res = (1LL << (n+1)) - 2;

	cout << res;
	return 0;
}