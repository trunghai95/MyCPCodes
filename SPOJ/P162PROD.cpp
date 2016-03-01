#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[6];

int main()
{
	for (int i = 0; i < 6; ++i)
		cin >> a[i];
	ll tmp = a[0] + a[1] + a[2];

	cout << tmp*tmp - a[0]*a[0] - a[2]*a[2] - a[4]*a[4];
	return 0;
}